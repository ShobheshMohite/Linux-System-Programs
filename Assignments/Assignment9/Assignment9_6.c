//WAP which is used to display Environment of our running process
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) 
{
    // Iterate through the environment variables

    for (int i = 0; envp[i] != NULL; i++) 
    {
        printf("Environment[%d]: %s\n", i, envp[i]);
    }

    return 0;
}
