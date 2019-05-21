#include "head.h"

int main(int argc,char* argv[])
{
    int fd = -1,ret = 0;
    int offset = 0;
    char buf = '\0';

    if(argc < 2)
    {
        printf("argument too few\n");
        return 1;
    }

    fd = open(argv[1],O_RDONLY);
    if(fd < 0)
    {
        printf("Open %s failed in %s at %d\n",argv[1],__FILE__,__LINE__);
        return 2;
    }

    offset = lseek(fd,9,SEEK_SET);
    ret = read(fd,&buf,1);
    printf("%d\n",offset);
    printf("%c\n",buf);
    printf("%d\n",ret);

    close(fd);
    return 0;
}