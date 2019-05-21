#include "head.h"

typedef struct student
{
    char cName[20];
    int iAge;
    float fScore;
}Stu;

char * filepath = "f2";

int main(int argc,char* argv[])
{
    int fd = -1,ret = 0;
    Stu A = {"jack",18,79.3};
    char buf[100] = {'\0'};
    char temp[16] = {'\0'};

    sprintf(buf,"%s",A.cName);
    strcat(buf,"#");
    sprintf(temp,"%d",A.iAge);
    strcat(buf,temp);
    strcat(buf,"#");
    sprintf(temp,"%.1f",A.fScore);
    strcat(buf,temp);

    fd = open(filepath,O_WRONLY | O_CREAT | O_TRUNC,0666);
    if(fd < 0)
    {
        printf("Open %s failed in %s at %d\n",filepath,__FILE__,__LINE__);
        return 1;
    }

    ret = write(fd,buf,strlen(buf));

    close(fd);
    return 0;
}