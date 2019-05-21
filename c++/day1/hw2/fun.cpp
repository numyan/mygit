#include "head.h"

point::point(int _x,int _y):
x(_x),
y(_y)
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

void point::displayPoint()
{
    cout << "x:" << x <<endl;
    cout << "y:" << y <<endl;
}

Circle::Circle(point _center,int _radius):
center(_center),
radius(_radius)
{}

Circle::~Circle()
{}

void Circle::setCenter(point _center)
{
    center = _center;
}

point Circle::getCenter()
{
    return center;
}

void Circle::setRadius(int _radius)
{
    radius = _radius;
}

int Circle::getRadius()
{
    return radius;
}

void Circle::displayCircle()
{
    cout << "center:" << endl;
    cout << "x:" << center.getX() << "\t" << "y:" << center.getY() << endl;
    cout << "radius:\n" << radius << endl;
}