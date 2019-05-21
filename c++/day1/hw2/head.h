#ifndef _HEAH_H_
#define _HEAD_H_

#include <iostream>

using namespace std;

#include <cstdio>
#include <cstdlib>
#include <cstring>

class point
{
private:
    int x;
    int y;
public:
    point();
    point(int _x,int _y);
    
    void setX(int _x);
    int getX();

    void setY(int _y);
    int getY();

    void displayPoint();
};

class Circle
{
private:
    point center;
    int radius;
public:
    Circle();
    Circle(point center,int radius);
    ~Circle();

    void setCenter(point _center);
    point getCenter();

    void setRadius(int _radius);
    int getRadius();

    void displayCircle();
};

#endif