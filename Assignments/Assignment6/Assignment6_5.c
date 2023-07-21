//WAP which accept file name from user and offset,remove all the data from that offset
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <file_name> <offset>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    long offset = atol(argv[2]);

    FILE* file = fopen(filename, "r+");
    if (file == NULL) {
        printf("Error: Failed to open the file '%s'\n", filename);
        return 1;
    }

    // Move the file pointer to the specified offset
    fseek(file, offset, SEEK_SET);

    // Truncate the file from the current position
    if (ftruncate(fileno(file), ftell(file)) != 0) {
        printf("Error: Failed to truncate the file\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    printf("Data removed from offset %ld in the file '%s'\n", offset, filename);

    return 0;
}
