// file_compare.c

#include <stdio.h>
#include <string.h>

int compareFiles(const char* file1, const char* file2) {
    FILE* fp1 = fopen(file1, "r");
    if (!fp1) {
        perror("Error opening file 1");
        return -1;
    }

    FILE* fp2 = fopen(file2, "r");
    if (!fp2) {
        perror("Error opening file 2");
        fclose(fp1);
        return -1;
    }

    int equal = 1;
    char ch1, ch2;

    while ((ch1 = fgetc(fp1)) != EOF) {
        ch2 = fgetc(fp2);

        if (ch1 != ch2) {
            equal = 0;
            break;
        }
    }

    if (ch2 != EOF) {
        equal = 0;
    }

    fclose(fp1);
    fclose(fp2);

    return equal;
}
