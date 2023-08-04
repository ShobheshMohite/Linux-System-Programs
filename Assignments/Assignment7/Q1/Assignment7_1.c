// main.c
#include <stdio.h>
#include <dlfcn.h>
#include "arithmetic.h"

int main() {
    void* ptr = dlopen("./libarithmetic.so", RTLD_LAZY);
    if (!ptr) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    int a = 10, b = 5;

    // Load the function pointers from the shared library
    int (*add_func)(int, int) = dlsym(ptr, "add");
    int (*subtract_func)(int, int) = dlsym(ptr, "subtract");
    int (*multiply_func)(int, int) = dlsym(ptr, "multiply");
    int (*divide_func)(int, int) = dlsym(ptr, "divide");

    if (!add_func || !subtract_func || !multiply_func || !divide_func) {
        fprintf(stderr, "Error: %s\n", dlerror());
        dlclose(ptr);
        return 1;
    }

    printf("Addition: %d\n", add_func(a, b));
    printf("Subtraction: %d\n", subtract_func(a, b));
    printf("Multiplication: %d\n", multiply_func(a, b));
    printf("Division: %d\n", divide_func(a, b));

    dlclose(ptr);
    return 0;
}
