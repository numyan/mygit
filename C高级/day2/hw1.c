#include "head.h"

int main(int argc,char* argv[])
{
    int fd = 0,retRead = 1,retWrite = 1;
    char buf = '\0';
    char buf1 = '\n';

    if(argc < 2)
    {
        printf("argument is too few\n");
        return 1;
    }

    fd = open(argv[1],O_RDONLY);
    if(fd < 0)
    {
        printf("Open %s failed in %s at %d",argv[1],__FILE__,__LINE__);
        return 2;
    }

    while(retRead)
    {
        retRead = read(fd,&buf,1);
        retWrite = write(1,&buf,1);
    }

    retWrite = write(1,&buf1,1);

    close(fd);
    return 0;
}