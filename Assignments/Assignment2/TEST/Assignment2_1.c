//PROGRAM14
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

#define BLOCKSIZE 1024 //USER DEFINED MACRO

int main(int argc , char *argv[])
{
    int fd = 0;
    int Ret = 0;  
    char Buffer [BLOCKSIZE];


    if(argc != 2)
    {
        printf("Invalid Number Of Arguments \n");
        return-1;
    }


    fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        printf("Unable To Open File \n");  
    }

    while((Ret = read(fd,Buffer,sizeof(Buffer))) != 0) //ANGHOL
    {
        write(1,Buffer,Ret);
    }

    close(fd);

    return 0;
}
