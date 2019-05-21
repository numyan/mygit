#include "head.h"

car::car(int _num,string _brand,double _price,enum MainColor _color)
:num(_num),
 brand(_brand),
 price(_price),
 color(_color)
{}

car::~car()
{}

void car::setNum(int _num)
{
    num = _num;
}

int car::getNum()
{
    return num;
}

string car::getBrand()
{
    return brand;
}

void car::setBrand(const string _brand)
{
    brand = _brand;
}

void car::setPrice(double _price)
{
    price = _price;
}

double car::getPrice()
{
    return price;
}

void car::setColor(enum MainColor _color)
{
    color = _color;
}
enum MainColor car::getColor()
{
    return color;
}

void car::CarAdvertise()
{
    cout << "wheel num:" << num << endl;
    cout << "car brand:" << brand << endl;
    cout << "car price:" << price << endl;
    cout << "car color:" << color << endl;
}

