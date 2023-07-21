#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main() {
    const char* filename = "file_with_hole.txt";
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: Failed to create the file '%s'\n", filename);
        return 1;
    }

    // Write some content to the file
    const char* content = "This is the content of the file.";
    fwrite(content, sizeof(char), strlen(content), file);

    // Seek to the position to create the hole (1KB from the current position)
    fseek(file, 1024, SEEK_CUR);

    // Write a null byte to create the hole
    char null_byte = '\0';
    fwrite(&null_byte, sizeof(char), 1, file);

    // Close the file
    fclose(file);

    printf("File with hole created successfully: %s\n", filename);

    return 0;
}
