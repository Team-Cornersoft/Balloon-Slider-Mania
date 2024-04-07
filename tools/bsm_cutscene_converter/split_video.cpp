#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <opencv2/opencv.hpp>
#include <png.h>
#include <ftw.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>

#define ABS(x) ({         \
    int32_t _x = (x); \
    _x > 0 ? _x : -_x; })

#define CROP_WIDTH  178
#define CROP_HEIGHT 82

#define PIXEL_SIZE_BYTES 1
#define IMG_FMT ".bmp"

int32_t X_OFFSET = 71;
int32_t Y_OFFSET = 79;

float INPUT_FRAMERATE   = 60.0f;
float DESIRED_FRAMERATE = 30.0f;

uint8_t paletteData[256 * 4];
uint8_t inputData[CROP_WIDTH * CROP_HEIGHT * 4];

const char suffix[] = ".ci8" IMG_FMT;

uint8_t paletteTable[32] = {
      0,   8,  16,  24, 
     33,  41,  49,  57,
     66,  74,  82,  90,
     99, 107, 115, 123,
    132, 140, 148, 156,
    165, 173, 181, 189,
    198, 206, 214, 222,
    231, 239, 247, 255,
};

int unlink_cb(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf)
{
    int rv = remove(fpath);

    if (rv)
        perror(fpath);

    return rv;
}

// Compare function for qsort
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void writeCI8(const char *inputFilename, const char *outputFilename, const char *outputDir) {
    char paletteNameBuf[512];
    FILE *outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        perror("Error opening output ci8 file");
        return;
    }

    FILE *inputFile = fopen(inputFilename, "rb");
    if (inputFile == NULL) {
        perror("Error reading input " IMG_FMT " file");
        fclose(outputFile);
        return;
    }
    fseek(inputFile, 0x36, SEEK_SET);

    for (int i = (CROP_HEIGHT - 1); i >= 0; i--) {
        fread(inputData + (CROP_WIDTH * 4 * i), 1, CROP_WIDTH * 4, inputFile);
    }
    fclose(inputFile);

    // Generate palette
    sprintf(paletteNameBuf, "ffmpeg -i %s -y -pix_fmt rgb555le -vf palettegen %s/palette" IMG_FMT " 2> /dev/null",
        inputFilename,
        outputDir
    );
    system(paletteNameBuf);

    // Open generated palette
    sprintf(paletteNameBuf, "%s/palette" IMG_FMT, outputDir);
    FILE *paletteFile = fopen(paletteNameBuf, "rb");
    if (paletteFile == NULL) {
        perror("Error opening palette file");
        fclose(outputFile);
        return;
    }

    // Read palette
    fseek(paletteFile, 0x36, SEEK_SET);
    for (int i = 16 - 1; i >= 0; i--) {
        fread(paletteData + (16 * 2 * i), 1, 16 * 2, paletteFile);
    }
    fread(paletteData, 1, sizeof(paletteData) / 2, paletteFile);
    fclose(paletteFile);

    // Decode BMP data
    for (int32_t i = (sizeof(paletteData) / 2) - 2; i >= 0; i -= 2) {
        uint16_t palettePixel = ((uint16_t) paletteData[i]) + ((uint16_t) paletteData[i+1] << 8);

        paletteData[(i * 2)] = paletteTable[((palettePixel >> 10) & 0x1F)];
        paletteData[(i * 2) + 1] = paletteTable[((palettePixel >> 5) & 0x1F)];
        paletteData[(i * 2) + 2] = paletteTable[((palettePixel >> 0) & 0x1F)];
        paletteData[(i * 2) + 3] = 0xFF;
    }

    for (int i = 0; i < sizeof(inputData); i += 4) {
        int32_t diff;
        int32_t maxDiff = 0x7FFFFFFF;
        int32_t bestIndex = 0;
        for (int j = 0; j < sizeof(paletteData); j += 4) {
            diff = 0;

            diff += ABS((int32_t) inputData[i+2] - (int32_t) paletteData[j]);
            diff += ABS((int32_t) inputData[i+1] - (int32_t) paletteData[j+1]);
            diff += ABS((int32_t) inputData[i+0] - (int32_t) paletteData[j+2]);
            diff += ABS((int32_t) inputData[i+3] - (int32_t) paletteData[j+3]);

            if (diff < maxDiff) {
                maxDiff = diff;
                bestIndex = j / 4;
            }
        }

        fprintf(outputFile, "0x%02X,", (uint8_t) bestIndex);

        if ((i + 4) % (16 * 4) == 0) {
            fprintf(outputFile, "\n");
        }
    }

    fclose(outputFile);
}

void extractAndWriteFilenames(const char *videoPath, const char *directoryPath) {
    DIR *dir;
    struct dirent *ent;
    char **filenames = NULL;
    int numFiles = 0;

    int suffixLen = strlen(suffix);

    char shortSuffix[256];

    strncpy(shortSuffix, suffix, suffixLen);
    shortSuffix[suffixLen - 4] = '\0';

    // Extract video filename without extension
    std::string videoFilename = cv::samples::findFile(videoPath);
    size_t lastindex = videoFilename.find_last_of(".");
    videoFilename = videoFilename.substr(0, lastindex);
    std::string videoFilenameCFile = "dma_data/" + videoFilename + ".c.in";
    std::string videoFilenameCFilePal = "dma_data/" + videoFilename + "_pal.c.in";

    FILE *outputFile = fopen(videoFilenameCFile.c_str(), "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        return;
    }

    FILE *paletteOutputFile = fopen(videoFilenameCFilePal.c_str(), "w");
    if (paletteOutputFile == NULL) {
        perror("Error opening output file");
        fclose(outputFile);
        return;
    }

    // Open the directory
    if ((dir = opendir(directoryPath)) != NULL) {
        // Count the number of files with suffix extension
        while ((ent = readdir(dir)) != NULL) {
            size_t len = strlen(ent->d_name);
            if (len > suffixLen && strcmp(ent->d_name + len - suffixLen, suffix) == 0) {
                numFiles++;
            }
        }

        // Allocate memory for filenames
        filenames = (char **)malloc(numFiles * sizeof(char *));
        if (filenames == NULL) {
            perror("Memory allocation error");
            closedir(dir);
            return;
        }

        rewinddir(dir); // Reset directory stream to the beginning

        int index = 0;
        // Save filenames with suffix extension
        while ((ent = readdir(dir)) != NULL) {
            size_t len = strlen(ent->d_name);
            if (len > suffixLen && strcmp(ent->d_name + len - suffixLen, suffix) == 0) {
                filenames[index] = strdup(ent->d_name);
                index++;
            }
        }

        closedir(dir);

        // Sort filenames in alphabetical order
        qsort(filenames, numFiles, sizeof(char *), compare);

        fprintf(outputFile, "ALIGNED16 const Texture %s_video_data[] = {\n", videoFilename.c_str());

        fprintf(paletteOutputFile, "ALIGNED16 const Texture %s_video_palettes[] = {", videoFilename.c_str());

        // Write sorted filenames to output file
        for (int i = 0; i < numFiles; i++) {
            // Extract the filename without the extension
            size_t len = strlen(filenames[i]);
            char filename[256];
            char newFilename[512 + 32];
            char oldFilename[512 + 32];
            strncpy(filename, filenames[i], len - suffixLen);
            filename[len - suffixLen] = '\0';

            sprintf(oldFilename, "%s/%s", directoryPath, filenames[i]);
            sprintf(newFilename, "dma_data/%s%s.c.in", filename, shortSuffix);

            // Write the data
            fprintf(outputFile, "#include \"%s\"\n", newFilename);

            for (int j = (16 - ((CROP_WIDTH * CROP_HEIGHT * PIXEL_SIZE_BYTES) % 16)) % 16; j > 0; j--) {
                fprintf(outputFile, "0,");
            }

            fprintf(outputFile, "\n");

            // Write CI8 data
            writeCI8(oldFilename, newFilename, directoryPath);

            // Write palette generated within writeCI8
            for (int i = 0; i < sizeof(paletteData); i += 4) {
                if (i % (16 * 2) == 0) {
                    fprintf(paletteOutputFile, "\n    ");
                }

                uint16_t palettePixel = 0;
                palettePixel |= (uint16_t) ((paletteData[i] >> 3) & 0x1F) << 11;
                palettePixel |= (uint16_t) ((paletteData[i+1] >> 3) & 0x1F) << 6;
                palettePixel |= (uint16_t) ((paletteData[i+2] >> 3) & 0x1F) << 1;
                palettePixel |= 1;

                fprintf(paletteOutputFile, "0x%02X, 0x%02X, ", (palettePixel >> 8) & 0xFF, palettePixel & 0xFF);
            }

            free(filenames[i]); // Free allocated memory for each filename
        }
        fprintf(paletteOutputFile, "\n};\n");

        fprintf(outputFile, "};\n\n");
        fprintf(outputFile, "#include \"%s\"\n", videoFilenameCFilePal.c_str());

        fclose(outputFile);
        fclose(paletteOutputFile);
        free(filenames); // Free memory allocated for filenames array
    } else {
        // Unable to open directory
        perror("Unable to open directory");
    }
}

void splitFrames(const char *videoPath, const char *outputFolder) {
    char strBuff[512];

    // Create output folder if it doesn't exist, otherwise wipe it
    nftw(outputFolder, unlink_cb, 64, FTW_DEPTH | FTW_PHYS);
    if (mkdir(outputFolder, 0777) == -1) {
        fprintf(stderr, "Error creating output folder\n");
        return;
    }

    // Create dma_data folder if it doesn't exist, otherwise wipe it
    nftw("dma_data", unlink_cb, 64, FTW_DEPTH | FTW_PHYS);
    if (mkdir("dma_data", 0777) == -1) {
        fprintf(stderr, "Error creating dma_data folder\n");
        return;
    }

    // Extract video filename without extension
    std::string videoFilename = cv::samples::findFile(videoPath);
    size_t lastindex = videoFilename.find_last_of(".");
    videoFilename = videoFilename.substr(0, lastindex);

    // Generate png images
    sprintf(strBuff, "ffmpeg -i %s -pix_fmt bgra -vf fps=%d,crop=%d:%d:%d:%d %s/%s_%%04d%s 2> /dev/null",
        videoPath,
        (unsigned int) (DESIRED_FRAMERATE + 0.5f),
        CROP_WIDTH,
        CROP_HEIGHT,
        X_OFFSET,
        Y_OFFSET,
        outputFolder,
        videoFilename.c_str(),
        suffix
    );
    system(strBuff);

    extractAndWriteFilenames(videoPath, outputFolder);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <mp4 file> [-x xOffset] [-y yOffset] [-a desiredFramerate] [-b inputFramerate]\n", argv[0]);
        fprintf(stderr, "xOffset default: %d\nyOffset default: %d\ndesiredFramerate default: %f\ninputFramerate default: %f\n", X_OFFSET, Y_OFFSET, DESIRED_FRAMERATE, INPUT_FRAMERATE);
        return EXIT_FAILURE;
    }

    for (int32_t i = 2; i < argc; i++) {
        if (i + 1 == argc) {
            fprintf(stderr, "Usage: %s <mp4 file> [-x xOffset] [-y yOffset] [-a desiredFramerate] [-b inputFramerate]\n", argv[0]);
            return EXIT_FAILURE;
        }

        if (strcmp(argv[i], "-a") == 0) {
            DESIRED_FRAMERATE = atof(argv[i + 1]);
            i++;
            continue;
        }
        if (strcmp(argv[i], "-b") == 0) {
            INPUT_FRAMERATE = atof(argv[i + 1]);
            i++;
            continue;
        }
        if (strcmp(argv[i], "-x") == 0) {
            X_OFFSET = atoi(argv[i + 1]);
            i++;
            continue;
        }
        if (strcmp(argv[i], "-y") == 0) {
            Y_OFFSET = atoi(argv[i + 1]);
            i++;
            continue;
        }
        
        fprintf(stderr, "Usage: %s <mp4 file> [-x xOffset] [-y yOffset] [-a desiredFramerate] [-b inputFramerate]\n", argv[0]);
        return EXIT_FAILURE;
    }
	
	splitFrames(argv[1], "out");

    return EXIT_SUCCESS;
}
