#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "data.h"

#define PIPE_NAME "/tmp/myfifo"

int main(int argc,char* argv[])
{
    int ret = 0;
    int wfd = 0;
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

    printf("write process before open\n");
    wfd = open(PIPE_NAME,O_WRONLY);
    printf("write process after open\n");
    if(wfd < 0)
    {
        printf("open failed in %s at %d\n",__FILE__,__LINE__);
        return 2;
    }
    
    while(1)
    {
        system("clear");
        printf("Please input number of random:\n");
        scanf("%d",&n);
        getchar();
        if(0 == n)
        {
            write(wfd,&n,sizeof(int));
            return 0;
        }

        pst = (struct Data*)malloc(sizeof(n)+n*sizeof(int));
        if(NULL == pst)
        {
            printf("Malloc failed in %s at %d\n",__FILE__,__LINE__);
            return 3;
        }
        memset(pst,0,sizeof(n)+n*sizeof(int));

        srand(time(0));
        for(i = 0;i < n;i++)
        {
            *((pst->num) + i) = rand() % 100;
        }
        pst->n = n;
        write(wfd,pst,(n+1)*sizeof(int));

        free(pst);
        pst = NULL;
    }

    close(wfd);
    wfd = -1;
    return 0;
}