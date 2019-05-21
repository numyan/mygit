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
    ~point();
    
    void setX(int _x);
    int getX();

    void setY(int _y);
    int getY();

    void display();
};


#endif