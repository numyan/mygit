#include "head.h"

char* filePath = "pic.bmp";

int main(int argc,char* argv[])
{
    int width = 0;
    int height = 0;
    FILE* file = fopen(filePath,"r");
    if(NULL == file)
    {
        return 1;
    }

    fseek(file,18,SEEK_SET);
    fread(&width,4,1,file);
    fread(&height,4,1,file);
    fclose(file);

    printf("The width of picture is:%d\nThe height of picture is %d\n",width,height);

    return 0;
}