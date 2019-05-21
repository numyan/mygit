#include <pthread.h>

#include <stdio.h>

#include "head.h"

void* ThreadFunc(void* pv);

int main(int argc,char* argv[])
{
    pthread_t tid;
    int ret = 0,i = 0;

    ret = pthread_create(&tid,NULL,ThreadFunc,&i);
    if(ret != 0)
    {
        printf("thread failed in %s at %d\n",__FILE__,__LINE__);
        return 1;
    }

    for(i = 0;i < 30;i++)
    {
        printf("I am in main thread %d .......\n",i);
    }

    pthread_exit(0);
    return 0;
}

void* ThreadFunc(void* pv)
{
    int i = *(int*)pv;
    for(i = 0;i < 30;i++)
    {
        printf("I am in new thread %d ......\n",i);
    }

    return NULL;
}

// int main(int argc,char* argv[])
// {
//     int ret = 0,i = 0;
//     pthread_t tid;

//     ret = pthread_create(tid,NULL,ThreadFunc,NULL);
//     if(ret != 0)
//     {
//         printf("thread failed in %s at %d",__FILE__,__LINE__);
//         return 1;
//     }

//     for(i = 0;i < 30;i++)
//     {
//         printf("I am in main thread %d.....\n",i);
//     }

//     return 0;
// }

