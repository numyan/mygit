#include <pthread.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include "head.h"

void* ThreadFunc(void* pv);

#define N 6
int garr[N] = {1,2,3,4,5,6};
pthread_mutex_t lock;

int main(int argc,char* argv[])
{
    pthread_t tid;
    int ret = 0;
    int i = 0;

    pthread_mutex_init(&lock,NULL);

    ret = pthread_create(&tid,NULL,ThreadFunc,NULL);
    if(ret != 0)
    {
        printf("pthread_create failed in %s at %d\n",__FILE__,__LINE__);
        pthread_mutex_destroy(&lock);
        return 1;
    }

    while(1)
    {
        sleep(1);
        pthread_mutex_lock(&lock);
        for(i = 0;i < N;i++)
        {
            if(-1 != garr[i])
            {
                break;
            }
        }
        if(N == i)
        {
            printf("Main thread will exit\n");
            pthread_mutex_unlock(&lock);
            break;
        }
        else
        {
            printf("In main thread using %d at %d\n",garr[i],i);
            garr[i] = -1;
        }
        pthread_mutex_unlock(&lock);        
    }

    pthread_join(tid,NULL);
    printf("After join\n");
    pthread_mutex_destroy(&lock);
    return 0;
}

void* ThreadFunc(void* pv)
{
    int i = 0;

    while(1)
    {
        sleep(1);
        pthread_mutex_lock(&lock);
        for(i = 0;i < N;i++)
        {
            if(-1 != garr[i])
            {
                break;
            }
        }
        if(N == i)
        {
            printf("Main thread will exit\n");
            pthread_mutex_unlock(&lock);
            break;
        }
        else
        {
            printf("In new thread using %d at %d\n",garr[i],i);
            garr[i] = -1;
        }
        pthread_mutex_unlock(&lock);
    }

    return NULL;
}