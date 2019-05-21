#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"

#define PIPE_NAME "/tmp/myfifo"


int Intcmp(const void* pv1,const void* pv2)
{
    return *(int*)pv1 - *(int*)pv2;
}

int main(int argc,char* argv[])
{
    int ret = 0;
    int rfd = 0;
    int n = 0;
    int i = 0;
    struct Data* pst = NULL;

    if(access(PIPE_NAME,F_OK))
    {
        ret = mkfifo(PIPE_NAME,0666);
        if(ret < 0)
        {
            printf("mkfifo failed in %s at %d\n",__FILE__,__LINE__);
            return 1;
        }
    }

    printf("read process before open\n");
    rfd = open(PIPE_NAME,O_RDONLY);
    printf("read process after open\n");
    if(rfd < 0)
    {
        printf("open fifo failed in %s at %d\n",__FILE__,__LINE__);
        return 2;
    }

    while(1)
    {
        read(rfd,&n,sizeof(int));
        if(n == 0)
        {
            return 0;
        }

        pst = (struct Data*)malloc((n+1)*sizeof(int));
        if(NULL == pst)
        {
            printf("Malloc failed in %s at %d\n",__FILE__,__LINE__);
            return 3;
        }
        memset(pst,0,(n+1)*sizeof(int));
        pst->n = n;

        read(rfd,pst->num,n*sizeof(int));
        qsort(pst->num,n,sizeof(int),Intcmp);
        printf("read %d random number,sort from large to small:\n");
        for(i = 0;i < n;i++)
        {
            printf("%d\n",*((pst->num)+i));
        }
        free(pst);
        pst = NULL;
    }

    close(rfd);
    rfd = -1;
    return 0;
}