#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <opencv2/opencv.hpp>
#include <png.h>
#include <ftw.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>

#define CROP_WIDTH  178
#define CROP_HEIGHT 82

int32_t X_OFFSET = 0;
int32_t Y_OFFSET = 0;

float DESIRED_FRAMERATE = 30.0f;

const char suffix[] = ".rgba16.bmp";

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

void extractAndWriteFilenames(const char *videoPath, const char *directoryPath) {
    DIR *dir;
    struct dirent *ent;
    char **filenames = NULL;
    int numFiles = 0;

    int suffixLen = strlen(suffix);

    char shortSuffix[256];
    char tmpbuf[512];
    strncpy(shortSuffix, suffix, suffixLen);
    shortSuffix[suffixLen - 4] = '\0';

    // Extract video filename without extension
    std::string videoFilename = cv::samples::findFile(videoPath);
    size_t lastindex = videoFilename.find_last_of(".");
    videoFilename = videoFilename.substr(0, lastindex);
    std::string videoFilenameCFile = videoFilename + ".c.in";

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

        FILE *outputFile = fopen(videoFilenameCFile.c_str(), "w");
        if (outputFile == NULL) {
            perror("Error opening output file");
            return;
        }

        char *structBuf = (char *) malloc(0x1000000);
        if (!structBuf) { 
            perror("Error allocating structBuf data");
            return;
        }

        // Write sorted filenames to output file
        for (int i = 0; i < numFiles; i++) {
            // Extract the filename without the extension
            size_t len = strlen(filenames[i]);
            char filename[256];
            strncpy(filename, filenames[i], len - suffixLen);
            filename[len - suffixLen] = '\0';

            // Write the data
            fprintf(outputFile, "ALIGNED16 const Texture %s_video_data_%04d[] = {\n", videoFilename.c_str(), i+1);
            fprintf(outputFile, "#include \"dma_data/%s%s.yay0.c.in\"\n", filename, shortSuffix);
            fprintf(outputFile, "};\n");

            std::string path = std::string("") + directoryPath + "/" + std::string(filenames[i]);
            std::string path2 = std::string("") + "out2_tmp" + "/" + std::string(filename) + "_headerless";
            std::string path3 = std::string("") + "out3_tmp" + "/" + std::string(filename) + "_yay0";
            std::string path4 = std::string("") + "dma_data" + "/" + std::string(filename) + std::string(shortSuffix) + ".yay0.c.in";

            free(filenames[i]); // Free allocated memory for each filename

            FILE *readImage = fopen(path.c_str(), "rb");
            if (readImage == NULL) {
                perror("Error opening readImage output file");
                continue;
            }
            FILE *writeImage = fopen(path2.c_str(), "wb");
            if (writeImage == NULL) {
                perror("Error opening writeImage output file");
                fclose(readImage);
                continue;
            }

            fseek(readImage, 0x36, SEEK_SET);
            uint16_t *imgBuf = (uint16_t *) malloc(CROP_HEIGHT * CROP_WIDTH * sizeof(uint16_t));
            if (!imgBuf) {
                perror("Error allocating image buffer data");
                fclose(readImage);
                fclose(writeImage);
                continue;
            }
            uint8_t *imgBufOut = (uint8_t *) malloc(CROP_HEIGHT * CROP_WIDTH * sizeof(uint16_t));
            if (!imgBufOut) {
                perror("Error allocating image buffer data");
                free(imgBuf);
                fclose(readImage);
                fclose(writeImage);
                continue;
            }

            for (int32_t i = CROP_HEIGHT - 1; i >= 0; i--) {
                fread(&imgBuf[CROP_WIDTH * i], sizeof(uint16_t), CROP_WIDTH, readImage);
            }

            for (int32_t i = 0; i < CROP_HEIGHT * CROP_WIDTH; i++) {
                imgBuf[i] = (imgBuf[i] << 1) | 1;
                imgBufOut[(i * 2)] = (imgBuf[i] >> 8) & 0xFF;
                imgBufOut[(i * 2) + 1] = imgBuf[i] & 0xFF;
            }

            fwrite(imgBufOut, 1, CROP_HEIGHT * CROP_WIDTH * sizeof(uint16_t), writeImage);

            free(imgBuf);
            free(imgBufOut);
            fclose(readImage);
            fclose(writeImage);

            sprintf(tmpbuf, "../slienc %s %s", path2.c_str(), path3.c_str());
            system(tmpbuf);

            readImage = fopen(path3.c_str(), "rb");
            if (readImage == NULL) {
                perror("Error opening readImage output file");
                continue;
            }
            writeImage = fopen(path4.c_str(), "w");
            if (writeImage == NULL) {
                perror("Error opening writeImage output file");
                fclose(readImage);
                continue;
            }

            fseek(readImage, 0, SEEK_END);
            size_t yay0Size = ftell(readImage);
            size_t yay0SizeAligned = (yay0Size + 15) & ~0x0F;
            fseek(readImage, 0, SEEK_SET);

            uint8_t *buf = (uint8_t *) malloc(yay0SizeAligned);
            if (!buf) { 
                perror("Error allocating yay0 buffer data");
                fclose(readImage);
                fclose(writeImage);
                continue;
            }
            bzero(buf, yay0SizeAligned);

            fread(buf, 1, yay0Size, readImage);
            fclose(readImage);

            for (size_t i = 0; i < yay0SizeAligned; i++) {
                if ((i % 16) == 0 && i != 0) {
                    fprintf(writeImage, "\n");
                }
                fprintf(writeImage, "0x%02X,", buf[i]);
            }

            free(buf);
            fclose(writeImage);

            sprintf(structBuf, "%s    {.address = %s_video_data_%04d, .compressedSize = 0x%02X},\n", structBuf, videoFilename.c_str(), i+1, (uint32_t) yay0SizeAligned);
        }

        fprintf(outputFile, "\n");
        fprintf(outputFile, "ALIGNED16 const struct DMAVideoProps %s_video_data[%d] = {\n", videoFilename.c_str(), numFiles);
        fprintf(outputFile, "%s", structBuf);
        fprintf(outputFile, "};\n");

        fclose(outputFile);
        free(structBuf);
        free(filenames); // Free memory allocated for filenames array
    } else {
        // Unable to open directory
        perror("Unable to open directory");
    }
}

void splitFrames(const char *videoPath, const char *outputFolder) {
    char strBuff[512];
    nftw(outputFolder, unlink_cb, 64, FTW_DEPTH | FTW_PHYS);
    nftw("out2_tmp", unlink_cb, 64, FTW_DEPTH | FTW_PHYS);
    nftw("out3_tmp", unlink_cb, 64, FTW_DEPTH | FTW_PHYS);
    nftw("dma_data", unlink_cb, 64, FTW_DEPTH | FTW_PHYS);

    // Create output folder if it doesn't exist
    if (mkdir(outputFolder, 0777) == -1) {
        fprintf(stderr, "Error creating output folder\n");
        return;
    }
    // Create output folder if it doesn't exist
    if (mkdir("out2_tmp", 0777) == -1) {
        fprintf(stderr, "Error creating output folder\n");
        return;
    }
    // Create out3_tmp folder if it doesn't exist
    if (mkdir("out3_tmp", 0777) == -1) {
        fprintf(stderr, "Error creating output folder\n");
        return;
    }
    // Create dma_data folder if it doesn't exist
    if (mkdir("dma_data", 0777) == -1) {
        fprintf(stderr, "Error creating output folder\n");
        return;
    }

    // Extract video filename without extension
    std::string videoFilename = cv::samples::findFile(videoPath);
    size_t lastindex = videoFilename.find_last_of(".");
    videoFilename = videoFilename.substr(0, lastindex);

    // Generate png images
    sprintf(strBuff, "ffmpeg -i %s -pix_fmt rgb555le -vf fps=%d,crop=%d:%d:%d:%d %s/%s_%%04d%s 2> /dev/null",
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
        fprintf(stderr, "Usage: %s <mp4 file> [-x xOffset] [-y yOffset] [-a desiredFramerate]\n", argv[0]);
        fprintf(stderr, "xOffset default: %d\nyOffset default: %d\ndesiredFramerate default: %f\n", X_OFFSET, Y_OFFSET, DESIRED_FRAMERATE);
        return EXIT_FAILURE;
    }

    for (int32_t i = 2; i < argc; i++) {
        if (i + 1 == argc) {
            fprintf(stderr, "Usage: %s <mp4 file> [-x xOffset] [-y yOffset] [-a desiredFramerate]\n", argv[0]);
            return EXIT_FAILURE;
        }

        if (strcmp(argv[i], "-a") == 0) {
            DESIRED_FRAMERATE = atof(argv[i + 1]);
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
	
	splitFrames(argv[1], "out1_tmp");

    return EXIT_SUCCESS;
}
