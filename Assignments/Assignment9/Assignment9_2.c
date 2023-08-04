#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

int main() 
{
    pid_t pid1, pid2;

    // Create process 1
    pid1 = fork();

    if (pid1 < 0) 
    {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } 
    else if (pid1 == 0) 
    {
        // This is process 1
        int count = 0;
        
        // Count capital characters in demo.txt
        FILE *file = fopen("demo_file.txt", "r");
        if (file != NULL) {
            int ch;
            while ((ch = fgetc(file)) != EOF) 
            {
                if (isupper(ch)) 
                {
                    count++;
                }
            }
            fclose(file);
        }
        
        // Write the count to count1.txt
        FILE *countFile = fopen("count1.txt", "w");
        if (countFile != NULL) 
        {
            fprintf(countFile, "Process 1 count: %d\n", count);
            fclose(countFile);
        } 
        else 
        {
            perror("Failed to open count1.txt");
        }
        
        exit(EXIT_SUCCESS);
    } 
    else 
    {
        // Parent process
        // Create process 2
        pid2 = fork();
        
        if (pid2 < 0) 
        {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        } 
        else if (pid2 == 0) 
        {
            // This is process 2
            int count = 0;
            
            // Count capital characters in hello.txt
            FILE *file = fopen("hello.txt", "r");
            if (file != NULL) 
            {
                int ch;
                while ((ch = fgetc(file)) != EOF) 
                {
                    if (isupper(ch)) 
                    {
                        count++;
                    }
                }
                fclose(file);
            }
            
            // Write the count to count2.txt
            FILE *countFile = fopen("count2.txt", "w");
            if (countFile != NULL) 
            {
                fprintf(countFile, "Process 2 count: %d\n", count);
                fclose(countFile);
            } 
            else 
            {
                perror("Failed to open count2.txt");
            }
            
            exit(EXIT_SUCCESS);
        } 
        else 
        {
            // Parent process
            // Wait for both child processes to finish
            int status;
            waitpid(pid1, &status, 0);
            waitpid(pid2, &status, 0);
            
            printf("Both processes have finished counting.\n");
        }
    }

    return 0;
}
