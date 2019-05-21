#include "head.h"

int main(int argc,char* argv[])
{
    pid_t fpid;
    pid_t gpid;
    fpid = fork();

    if(fpid < 0)
    {
        printf("fork failed in %s at %d\n",__FILE__,__LINE__);
        return 1;
    }
    else if(fpid > 0)
    {
        printf("parent processing id:%d\n",getpid());
        wait(NULL);
    }
    else
    {
        gpid = fork();
        if(gpid < 0)
        {
            printf("fork failed in %s at %d\n",__FILE__,__LINE__);
            return 2;
        }
        else if(gpid > 0)
        {
            printf("child processing id:%d\n",getpid());
        }
        else
        {
            printf("\ngrandchild processing id:%d\n",getpid());
        }
    }
    
    return 0;
}