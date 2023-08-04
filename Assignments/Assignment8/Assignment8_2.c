#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() 
{
    pid_t pid1, pid2, pid3;

    // Create process 2
    pid1 = fork();
    
    if (pid1 < 0) 
    {
        printf("Fork failed");
        exit(EXIT_FAILURE);
    } 
    else if (pid1 == 0) 
    {
        // This is process 2
        printf("Process 2 created by Process 1 (Parent PID: %d)\n", getppid());
        
        // Create process 3
        pid2 = fork();
        
        if (pid2 < 0) 
        {
            printf("Fork failed");
            exit(EXIT_FAILURE);
        }
        else if (pid2 == 0) 
        {
            // This is process 3
            printf("Process 3 created by Process 2 (Parent PID: %d)\n", getppid());
        } 
        else 
        {
            // Process 2
            wait(NULL); // Wait for process 3 to finish
        }
    }   
        else 
        {
            // Process 1
            printf("Process 1 (PID: %d) is waiting for Process 2 to terminate\n", getpid());
            wait(NULL); // Wait for process 2 to finish
            printf("All processes have terminated\n");
        }

    return 0;
}
