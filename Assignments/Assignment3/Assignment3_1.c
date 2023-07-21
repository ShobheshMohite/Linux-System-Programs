//COPY DATA FROM EXISITNG FILE TO NEW FILE
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc ,char *argv[])
{
    int fdSource = 0;
    int fdDest = 0;
    int ret = 0;

    char Buffer[BLOCKSIZE] = {'\0'};

    if(argc != 3)
    {
        printf("Insufficient Arguments \n");
    }

    fdSource = open(argv[1],O_RDONLY);
    if(fdSource == -1)
    {
        printf("Unable To Open File \n");
        return -1;
    }

    fdDest = creat(argv[2],0777);
    if(fdDest == -1)
    {
        printf("Unable To Create Destination File\n");
        close(fdSource);
        return -1;
    }

    while ((ret = read(fdSource,Buffer,sizeof(Buffer)))!= 0)
    {
        write(fdDest,Buffer,ret);
        memset(Buffer,0,sizeof(Buffer));
    }
    
    close(fdSource);
    close(fdDest);

    return 0;
}