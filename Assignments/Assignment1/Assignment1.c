//open file 
#include<stdio.h>
#include<fcntl.h>

int main(int argc , char *argv[])
{
    int fd = 0;

    printf("Usage : Executable Name and Then File Name");

    if(argc !=2)
    {
        printf("Invalid Number Of Arguments \n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        printf("Unable To Open File \n");  
    }
    else
    {
        printf("File Is Successfully Opened With Fd : %d\n",fd);
    }
    
    return 0;
}
