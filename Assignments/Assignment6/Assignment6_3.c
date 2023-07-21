#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char dirname[256];
    printf("Enter the directory name where you want to create the file: ");
    scanf("%255s", dirname);

    char filename[256];
    sprintf(filename, "%s/new_file.txt", dirname);

    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Failed to create the file in the directory '%s'\n", dirname);
        return 1;
    }

    // Write some content to the file (optional)
    const char* content = "This is the content of the new file.\n";
    fputs(content, file);

    // Close the file
    fclose(file);

    printf("File created successfully in the directory '%s'\n", dirname);

    return 0;
}
