#include "file_info.h"
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

void displayFileInfo(const char* filename) {
    FILE* file = fopen(filename, "r");

    if (file) {
        // Calculate file size
        fseek(file, 0, SEEK_END);
        long file_size = ftell(file);
        fseek(file, 0, SEEK_SET);

        // Get file modification date
        struct stat file_stat;
        if (stat(filename, &file_stat) != 0) {
            printf("Error: Unable to get file information.\n");
            fclose(file);
            return;
        }
        char mod_time_str[20];
        strftime(mod_time_str, sizeof(mod_time_str), "%Y-%m-%d %H:%M:%S", localtime(&file_stat.st_mtime));

        printf("File information for %s:\n", filename);
        printf("File size: %ld bytes\n", file_size);
        printf("Last modified: %s\n", mod_time_str);
    } else {
        printf("Error: Unable to open the file.\n");
    }

    fclose(file);
}
