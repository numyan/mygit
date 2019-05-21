#include "head.h"

typedef struct student
{
    char name[16];
    int age;
    float score;
}Stu;

char* filePath = "f1";

int main (int argc,char *argv[])
{
    Stu stu[100];
    memset(stu,0,4*sizeof(Stu));
    FILE* file = NULL;
    int i = 0,j = 0,k = 0;

    file = fopen(filePath,"r");
    if(NULL == file)
    {
        printf("fopen failed %s,in %s at %d\n",argv[1],__FILE__,__LINE__);
        return 1;
    }
    while(1)
    {
        char str1[100] = {'\0'};
        char str2[100] = {'\0'};
        char str3[100] = {'\0'};
        int ret = 0;

        ret = fscanf(file,"%s",str1);
        if(ret == EOF)
        {
            fclose(file);
            break;
        }

        j = 0;
        k = 0;
        while(*(str1+j) != '#')
        {           
            stu[i].name[k] = *(str1+j);
            k++;
            j++;
        }

        char* p1 = strstr(str1,"#");
        strcpy(str2,p1);
        j = 1;
        k = 0;
        char age[8] = {'\0'};
        while(*(str2+j) != '#')
        {
            age[k] = *(str2+j);
            j++;
            k++;
        }
        sscanf(age,"%d",&stu[i].age);

        strcpy(str3,str2);
        j = 4;
        k = 0;
        char score[8] = {'\0'};
        while(*(str3+j) != '\0')
        {
            score[k] = *(str3+j);
            k++;
            j++;
        }
        sscanf(score,"%f",&stu[i].score);

        i++;
    }

    for(j = 0;j < i;j++)
    {
        printf("name:%s\nage:%d\nscore:%.1f\n",stu[j].name,stu[j].age,stu[j].score);
    }

    return 0;
}