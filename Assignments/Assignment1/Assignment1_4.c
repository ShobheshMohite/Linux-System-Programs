//Program that shows info about file
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc , char *argv[])
{
    int fd = 0;
    int mode = 0;
    struct stat sobj;

    printf("Usage : Name_Of_ExecutableFile File_Name\n");
    fd = open(argv[1],O_RDONLY);
    fstat(fd,&sobj);

    if(fd == -1)
    {
        printf("Unable To Open File Or File Doesn't Exist \n");  
        return -1;
    }

    if(argc == 2)
    {
        printf("File Name : %s\n",argv[1]);
        printf("File Size Is : %d\n",sobj.st_size);
        printf("Number Of Links : %d\n",sobj.st_nlink);
        printf("Inode Numbers : %d\n",sobj.st_ino);
        printf("File System Number : %d\n",sobj.st_dev);
        printf("Number Of Blocks : %d\n",sobj.st_blocks);
    }
    else
    {
        printf("Invalid Number Of Arguments \n");
        return -1;
    }
    
    return 0;
}
