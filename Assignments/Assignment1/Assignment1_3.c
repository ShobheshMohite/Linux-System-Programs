
//WRITE A PRO which accept file name and on mode and that program check wether our process can access that file in accepted mode or not
/*#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc , char *argv[])
{
    int fd = 0;
    int mode = 0;

    printf("Usage : Name_Of_ExecutableFile Name_Of_File Mode\n");

    if(argc != 3)
    {
        printf("Invalid Number Of Arguments \n");
        return -1;
    }

    if(strcmp(argv[2], "Read") == 0)
    {
        mode = O_RDONLY;
    }
    else if(strcmp(argv[2], "Write") == 0)
    {
        mode = O_WRONLY;
    }
    else
    {
        mode = O_RDONLY;
    }

    fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        printf("Unable To Open File \n");  
    }
    else
    {
        printf("File Is Successfully Opened With %s mode and with Fd : %d\n",argv[2],fd);
    }
    
    return 0;
}
*/