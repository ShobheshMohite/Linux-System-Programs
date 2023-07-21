#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc , char *argv[])
{
    int fd = 0;
    int mode = 0;   
    int ret = 0;
    char *Buffer = NULL;
    int Size = 0;

    printf("Usage : Executable_Name Source_File Number_Of_Bytes\n");

    if(argc != 3)
    {
        printf("Invalid Number Of Arguments \n");
        return-1;
    }

    Size = atoi(argv[2]);

    fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        printf("Unable To Open File \n");  
    }

    Buffer = (char*)malloc(Size);

    ret = read(fd,Buffer,Size);
    if(ret == 0)
    {
        printf("Unable To Read Data \n");
        return -1;
    }

    printf("Data From File Is : \n");
    write(1,Buffer,ret);
    
    return 0;
}
