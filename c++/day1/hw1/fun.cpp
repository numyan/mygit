#include "head.h"

point::point(int _x,int _y):
x(_x),
y(_y)
{}

point::~point()
{}

void point::setX(int _x)
{
    x = _x;
}
    
int point::getX()
{
    return x;
}

void point::setY(int _y)
{
    y = _y;
}
    
int point::getY()
{
    return y;
}

void point::display()
{
    cout << "x:" << x <<endl;
    cout << "y:" << y <<endl;
}