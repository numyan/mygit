#include "head.h"

int main(int argc,char* argv[])
{
    pid_t pid1;
    pid1 = fork();

    if(pid1 < 0)
    {
        printf("fork failed in %s at %d",__FILE__,__LINE__);
        return 1;
    }
    else if(pid1 > 0)
    {
        pid_t pid2;
        pid2 = fork();
        if(pid2 < 0)
        {
            printf("fork failed in %s at %d",__FILE__,__LINE__);
            return 2;
        }
        else if(pid2 > 0)
        {
            pid_t pid3;
            pid3 = fork();
            if(pid3 < 0)
            {
                printf("fork failed in %s at %d",__FILE__,__LINE__);
                return 3;
            }
            else if(pid3 >0)
            {
                printf("Parent processing %d\n",getpid());
                //sleep(30);
                wait(NULL);
            }
            else
            {
                printf("child processing 3 %d\n",getpid());
            }    
        }
        else
        {
            printf("child processing 2 %d\n",getpid());
        }
    }
    else
    {
        printf("childe processing 1 %d\n",getpid());
    }
    return 0;
}

// int main(int argc,char* argv[])
// {
//     pid_t pid;

// }