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

    char* dirname = argv[1];

    DIR* dir = opendir(dirname);
    if (dir == NULL) {
        printf("Error: Failed to open directory '%s'\n", dirname);
        return 1;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            char filepath[256];
            snprintf(filepath, sizeof(filepath), "%s/%s", dirname, entry->d_name);

            struct stat file_stat;
            if (stat(filepath, &file_stat) == 0) {
                if (file_stat.st_size < 1024) {
                    FILE* file = fopen(filepath, "r+");
                    if (file != NULL) {
                        fseek(file, 1024, SEEK_SET);
                        fputc('\0', file); // Write a null byte to create the hole
                        fclose(file);
                        printf("Hole created in the file '%s'\n", filepath);
                    }
                } else {
                    FILE* file = fopen(filepath, "r+");
                    if (file != NULL) {
                        if (ftruncate(fileno(file), 1024) == 0) {
                            printf("File '%s' truncated to 1KB\n", filepath);
                        } else {
                            printf("Error: Failed to truncate the file '%s'\n", filepath);
                        }
                        fclose(file);
                    }
                }
            } else {
                printf("Error: Failed to get file stats for '%s'\n", filepath);
            }
        }
    }

    closedir(dir);

    return 0;
}
