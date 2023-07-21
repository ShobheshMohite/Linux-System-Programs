#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory_name>\n", argv[0]);
        return 1;
    }

    char dirname[256];
    snprintf(dirname, sizeof(dirname), "%s", argv[1]);

    DIR* dir = opendir(dirname);
    if (dir == NULL) {
        printf("Error: Failed to open directory '%s'\n", dirname);
        return 1;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        char filepath[256];
        snprintf(filepath, sizeof(filepath), "%s/%s", dirname, entry->d_name);

        struct stat file_stat;
        if (stat(filepath, &file_stat) == 0) {
            if (S_ISREG(file_stat.st_mode) && file_stat.st_size > 100) {
                if (remove(filepath) == 0) {
                    printf("Deleted file: %s\n", filepath);
                } else {
                    printf("Error: Unable to delete file '%s'\n", filepath);
                }
            }
        } else {
            printf("Error: Failed to get file stats for '%s'\n", filepath);
        }
    }

    closedir(dir);

    return 0;
}
