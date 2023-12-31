#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc ,char *argv[])
{

    DIR *dp = NULL;
    struct dirent * entry = NULL;

    if(argc != 2)
    {
        printf("Insufficient Arguments \n");
        return -1;
    }

    dp = opendir(argv[1]);

    if(dp == NULL)
        {
            printf("Unable to open directory\n");
            return -1;
        }
    printf("---------------------------------------------\n");
    printf("Entries From The Directory Files Are : \n");
    printf("---------------------------------------------\n");
    printf("FILE NAME\n");

    while((entry = readdir(dp)) != NULL)
    {
        printf("%20s\n",entry->d_name);
    }
    printf("---------------------------------------------\n");

   return 0;
}