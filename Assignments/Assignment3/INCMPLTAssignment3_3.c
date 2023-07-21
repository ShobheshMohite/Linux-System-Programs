//MOVE ALL FILE FROM SOURCE TO DEST
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

void moveFile(const char* sourceDir, const char* destDir) {
    DIR *dir;
    struct dirent *entry;
    char sourcePath[256], destPath[256];

    dir = opendir(sourceDir);
    if (!dir) {
        printf("Error opening source directory: %s\n", sourceDir);
        return;
    }

    if (mkdir(destDir, 0777) == -1) {
        printf("Error creating destination directory: %s\n", destDir);
        closedir(dir);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(sourcePath, sizeof(sourcePath), "%s/%s", sourceDir, entry->d_name);
        snprintf(destPath, sizeof(destPath), "%s/%s", destDir, entry->d_name);

        if (rename(sourcePath, destPath) != 0)
            printf("Error moving file: %s\n", sourcePath);
        else
            printf("Moved file: %s\n", sourcePath);
    }

    closedir(dir);
}

int main() {
    char sourceDir[256], destDir[256];

    printf("Enter source directory name: ");
    scanf("%s", sourceDir);

    printf("Enter destination directory name: ");
    scanf("%s", destDir);

    moveFile(sourceDir, destDir);

    return 0;
}
