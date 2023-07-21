#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File '%s' not found.\n", filename);
        return 1;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[--len] = '\0'; // Remove the trailing newline character
        }

        FILE* current_file = fopen(buffer, "rb");
        if (current_file == NULL) {
            printf("Error: Cannot open file '%s'\n", buffer);
            continue;
        }

        fseek(current_file, 0, SEEK_END);
        long size = ftell(current_file);
        fclose(current_file);

        if (size > 10) {
            printf("%s - %ld bytes\n", buffer, size);
        }
    }

    fclose(file);

    return 0;
}
