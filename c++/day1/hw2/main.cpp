#include "head.h"

int main(int argc,char** argv)
{
    point center(1,2);
    Circle circle(center,3);

    circle.displayCircle();

    return 0;
}