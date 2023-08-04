//WAP which creates three different processes internally as process2,process3, process4.
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid2, pid3, pid4;

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
        } 
        else 
        {
            // Process 2
            wait(NULL); // Wait for process 3 to finish
            
            // Create process 4
            pid4 = fork();
            
            if (pid4 < 0) 
            {
                printf("Fork failed");
                exit(EXIT_FAILURE);
            }
            else if (pid4 == 0) 
            {
                // This is process 4
                printf("Process 4 created (PID: %d, Parent PID: %d)\n", getpid(), getppid());
            } 
            else 
            {
                // Process 2
                wait(NULL); // Wait for process 4 to finish
            }
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
