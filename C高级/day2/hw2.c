#include "head.h"

typedef struct student
{
    char cName[20];
    char cSex;
    int iAge;
    float fScore;
}Stu;

Stu stu[6] = 
    {
        {"jack",'M',20,78.8},
        {"rose",'F',18,46.1},
        {"bunny",'F',19,90.1},
        {"frank",'M',21,59.5},
        {"joe",'M',22,92.5},
        {"mike",'M',19,63.2}
    };

char * filePath = "f3";

int cmp(const void* a,const void* b)
{
    return (*(Stu*)a).fScore > (*(Stu*)b).fScore ? 1:-1;
}

int main(int argc,char* argv[])
{
    int fd = 0,ret = 0;
    int i = 0,j = 0;
    char buf = '\n';

    Stu* temp = (Stu*)malloc(2*sizeof(Stu));
    memset(temp,0,2*sizeof(Stu));

    qsort(stu,6,sizeof(stu[0]),cmp);

    fd = open(filePath,O_RDWR | O_TRUNC);
    if(fd < 0)
    {
        printf("Open %s failed in %s at %d\n",filePath,__FILE__,__LINE__);
        return 1;
    }

    for(i=0;i<6;i++)
    {
        ret = write(fd,stu+i,sizeof(Stu));
    }

    for(i=0;i<6;i++)
    {
        ret = read(fd,stu+i,sizeof(Stu));
        if((stu+i)->fScore < 60)
        {
            temp[j] = stu[i];
            j++;
        }
    }

    for(i=0;i<j;i++)
    {
        printf("%s %c %d %.1f\n",(temp+i)->cName,(temp+i)->cSex,(temp+i)->iAge,(temp+i)->fScore);
    }

    close(fd);
    free(temp);
    temp = NULL;
    return 0;
}