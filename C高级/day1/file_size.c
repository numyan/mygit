#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char* argv[])
{
    if(argc != 2)
    {
        printf("找不到该文件\n");
        return 1;                       //返回值为１，文件非正常退出
    }
    
    FILE* file = fopen(argv[1],"r");

    if(NULL == file)
    {
        printf("打开文件失败\n");
        return 1;
    }

    fseek(file,0,SEEK_END);
    int n = ftell(file);
    printf("文件占用%d\n",n);

    fclose(file);

    return;
}