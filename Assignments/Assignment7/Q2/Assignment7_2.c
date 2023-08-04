// main.c

#include <stdio.h>
#include <dlfcn.h>

typedef int (*compareFilesFunc)(const char*, const char*);

int main() {
    void* handle = dlopen("./libfilecompare.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error loading the shared library: %s\n", dlerror());
        return 1;
    }

    compareFilesFunc compare = (compareFilesFunc) dlsym(handle, "compareFiles");
    if (!compare) {
        fprintf(stderr, "Error loading the function: %s\n", dlerror());
        dlclose(handle);
        return 1;
    }

    const char* file1 = "a.txt"; // Replace with actual file names
    const char* file2 = "b.txt";

    int result = compare(file1, file2);
    if (result == 0) {
        printf("The contents of the files are the same.\n");
    } else {
        printf("The contents of the files are different.\n");
    }

    dlclose(handle);
    return 0;
}
