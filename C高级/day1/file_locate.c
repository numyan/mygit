#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char* argv[])
{
    if(argc < 2)
    {
        printf("缺少文件\n");
        return 1;                       //返回值为１，文件非正常退出
    }
    
    FILE* file = fopen(argv[1],"r");

    if(NULL == file)
    {
        printf("打开文件失败\n");
        return 1;
    }

    fseek(file,9,SEEK_SET);
    char c = fgetc(file);
    printf("第10个字符是：%c\n",c);

    fclose(file);
    file = NULL;

    return 0;
}