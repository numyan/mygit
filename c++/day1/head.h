#ifndef _HEAD_H_
#define _HEAD_H_

#include <iostream>

using namespace std;

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "string.h"

enum MainColor{white,black,red,orange,yellow,green,blue,purple};

class car
{
private:
    int num;
    string brand;
    double price;
    enum MainColor color;
public:
    //构造默认函数
    car(){};
    car(int _num,string _brand,double _price,enum MainColor _color);
    ~car();

    void setNum(int _num);
    int getNum();

    void setBrand(const string _brand);
    string getBrand();

    void setPrice(double _price);
    double getPrice();

    void setColor(enum MainColor _color);
    enum MainColor getColor();
    void CarAdvertise();
};

#endif