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

#define X_OFFSET    71
#define Y_OFFSET    79

#define INPUT_FRAMERATE   60.0f
#define DESIRED_FRAMERATE 30.0f

const char suffix[] = ".rgba16.png";

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
    strncpy(shortSuffix, suffix, suffixLen);
    shortSuffix[suffixLen - 4] = '\0';

    // Extract video filename without extension
    std::string videoFilename = cv::samples::findFile(videoPath);
    size_t lastindex = videoFilename.find_last_of(".");
    videoFilename = videoFilename.substr(0, lastindex);
    std::string videoFilenameCFile = videoFilename + ".c";

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

        fprintf(outputFile, "#include \"types.h\"\n");
        fprintf(outputFile, "#include \"macros.h\"\n\n");
        fprintf(outputFile, "ALIGNED16 const Texture %s_video_data[] = {\n", videoFilename.c_str());

        // Write sorted filenames to output file
        for (int i = 0; i < numFiles; i++) {
            // Extract the filename without the extension
            size_t len = strlen(filenames[i]);
            char filename[256];
            strncpy(filename, filenames[i], len - suffixLen);
            filename[len - suffixLen] = '\0';

            // Write the data
            fprintf(outputFile, "#include \"dma_data/%s%s.inc.c\"\n,\n", filename, shortSuffix);

            free(filenames[i]); // Free allocated memory for each filename
        }
        fprintf(outputFile, "};\n");

        fclose(outputFile);
        free(filenames); // Free memory allocated for filenames array
    } else {
        // Unable to open directory
        perror("Unable to open directory");
    }
}

void splitFrames(const char *videoPath, const char *outputFolder) {
    nftw(outputFolder, unlink_cb, 64, FTW_DEPTH | FTW_PHYS);

    cv::VideoCapture cap(videoPath);
    if (!cap.isOpened()) {
        fprintf(stderr, "Error opening video file\n");
        return;
    }

    // Extract video filename without extension
    std::string videoFilename = cv::samples::findFile(videoPath);
    size_t lastindex = videoFilename.find_last_of(".");
    videoFilename = videoFilename.substr(0, lastindex);

    // Create output folder if it doesn't exist
    if (mkdir(outputFolder, 0777) == -1) {
        fprintf(stderr, "Error creating output folder\n");
        return;
    }

    int totalFrames = cap.get(cv::CAP_PROP_FRAME_COUNT);
    cv::Mat frame;

    int framesElapsed = -1000;
    int framePrintIndex = 0;

    for (int frameNo = 0; frameNo < totalFrames; frameNo++) {
        if ((int) ((float) frameNo * DESIRED_FRAMERATE / INPUT_FRAMERATE + 0.01f) == (int) ((float) framesElapsed * DESIRED_FRAMERATE / INPUT_FRAMERATE + 0.01f)) {
            continue;
        }

        framesElapsed = frameNo;

        cap.set(cv::CAP_PROP_POS_FRAMES, frameNo);
        cap.read(frame);

        if (frame.empty()) {
            fprintf(stderr, "Error reading frame %d\n", frameNo);
            break;
        }

        cv::Rect cropRegion(X_OFFSET, Y_OFFSET, CROP_WIDTH, CROP_HEIGHT);
        cv::Mat croppedFrame = frame(cropRegion);

        char outputFilename[256];
        snprintf(outputFilename, sizeof(outputFilename), "%s/%s_%04d%s", outputFolder, videoFilename.c_str(), framePrintIndex++, suffix);

        std::vector<int> compression_params;
        compression_params.push_back(cv::IMWRITE_PNG_COMPRESSION);
        compression_params.push_back(9);  // Compression level: 0-9

        cv::imwrite(outputFilename, croppedFrame, compression_params);
    }

    cap.release();
    
    extractAndWriteFilenames(videoPath, outputFolder);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <mp4 file> [output folder]\n", argv[0]);
        return EXIT_FAILURE;
    }
	
	splitFrames(argv[1], ((argc >= 3) ? argv[2] : "out"));

    return EXIT_SUCCESS;
}
