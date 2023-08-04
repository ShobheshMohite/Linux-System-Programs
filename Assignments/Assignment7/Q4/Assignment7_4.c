// main.c
#include <stdio.h>
#include"outer.h"

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Call the function from the outer shared library
    unsigned long long result = call_factorial(num);

    printf("Factorial of %d is: %llu\n", num, result);

    return 0;
}
