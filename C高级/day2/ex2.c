#include "head.h"

int main(int argc,char* argv[])
{
    int fdR = -1,fdW = -1,ret1 = 0,ret2 = 0;

    if(argc < 3)
    {
        printf("Argument is too few\n");
        return 1;
    }

    fdR = open(argv[1],O_RDONLY);
    if(fdR < 0)
    {
        printf("Open %s failed in %s at %d\n",argv[1],__FILE__,__LINE__);
        return 2;
    }

    fdW = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,0666);
    if(fdW < 0)
    {
        printf("Open %s failed in %s at %d\n",argv[2],__FILE__,__LINE__);
        return 3;
    }

    ret1 = read(fdR,);
    ret2 = write();

    close(fdR);
    close(fdW);
    return 0;
}