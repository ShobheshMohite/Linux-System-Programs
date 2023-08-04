//WAP which is used to yield our processor by using appropriate system call
#include <stdio.h>
#include <sched.h>

int main() 
{
    // Yield the processor
    sched_yield();

    printf("Processor yielded\n");

    return 0;
}
