#include "head.h"

int gInt = 16;

int main(int argc,char* argv[])
{
    int lInt = 66;
    pid_t pid;

    pid = fork();
    gInt += 2;

    if(pid < 0)
    {
        printf("Fork failed in %s at %d\n",__FILE__,__LINE__);
        return 1;
    }

    if(pid > 0)
    {
        printf("gInt:%d,lInt:%d,pid:%d,parent\n",gInt,lInt,(int)getpid());
    }
    else
    {
        printf("gInt:%d,lInt:%d,pid:%d,child\n",gInt,lInt,(int)getpid());
        sleep(10);
    }
    
    printf("%d\n",gInt);

    return 0;
}