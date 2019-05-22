#include "singleton.h"

int main(int argc,char** argv)
{
    SingleTon* instance = SingleTon::getInstance();
    printf("%p\n",instance);
    return 0;
}