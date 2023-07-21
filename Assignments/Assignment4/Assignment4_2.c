//Create New Directory
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    char DirName[20];
    int fd = 0;

    printf("Enter A Directory Name : \n");
    scanf("%s",DirName);

    fd = mkdir(DirName,0777);
    if(fd == -1)
    {
        printf("Unable To Create Directory...\n");
    }
    else
    {
        printf("Directory Is Created With All Permissions..\n");
    }
       
    return 0;
}