// outer.c
#include <stdio.h>
#include <dlfcn.h>
#include"factorial.h"
#include"outer.h"

// Function that loads libfactorial.so and calls factorial function
unsigned long long call_factorial(int num) {
    void* factorial_lib = dlopen("libfactorial.so", RTLD_LAZY);

    if (!factorial_lib) {
        fprintf(stderr, "Error loading factorial library: %s\n", dlerror());
        return 0;
    }

    // Get function pointer to the factorial function from the loaded library
    unsigned long long (*factorial)(int) = dlsym(factorial_lib, "factorial");

    if (!factorial) {
        fprintf(stderr, "Error fetching factorial function: %s\n", dlerror());
        dlclose(factorial_lib);
        return 0;
    }

    // Call the factorial function
    unsigned long long result = factorial(num);

    // Close the loaded library
    dlclose(factorial_lib);

    return result;
}
