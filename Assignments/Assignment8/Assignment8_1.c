//WAP in which parent process waits till its child process terminate
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) 
    {
        printf"Fork failed");
        exit(EXIT_FAILURE);
    } 
    else if (pid == 0) 
    {
        // This is the child process
        printf("Child process is running\n");
        exit(EXIT_SUCCESS);
    } 
    else 
    {
        // This is the parent process
        printf("Parent process is waiting for the child to terminate\n");
        wait(NULL); // Wait for the child process to terminate
        printf("Child process has terminated, parent process is exiting\n");
        exit(EXIT_SUCCESS);
    }

    return 0;
}
