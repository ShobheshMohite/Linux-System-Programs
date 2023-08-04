//WAP which creates two processes as process2 and process3 and our //parent process terminates till both the processes terminates.
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() 
{
    pid_t pid2, pid3;

    // Create process 2
    pid2 = fork();
    
    if (pid2 < 0) 
    {
        printf("Fork failed");
        exit(EXIT_FAILURE);
    } 
    else if (pid2 == 0) 
    {
        // This is process 2
        printf("Process 2 created (PID: %d, Parent PID: %d)\n", getpid(), getppid());
        sleep(3); // Simulating some work in Process 2
        printf("Process 2 (PID: %d) has terminated\n", getpid());
    } 
    else 
    {
        // Create process 3
        pid3 = fork();
        
        if (pid3 < 0) 
        {
            printf("Fork failed");
            exit(EXIT_FAILURE);
        }
        else if (pid3 == 0) 
        {
            // This is process 3
            printf("Process 3 created (PID: %d, Parent PID: %d)\n", getpid(), getppid());
            sleep(2); // Simulating some work in Process 3
            printf("Process 3 (PID: %d) has terminated\n", getpid());
        } 
        else 
        {
            // Parent process
            printf("Parent process (PID: %d) is waiting for child processes to terminate\n", getpid());
            wait(NULL); // Wait for any child process to finish
            wait(NULL); // Wait for the other child process to finish
            printf("All child processes have terminated, parent process is exiting\n");
        }
    }

    return 0;
}
