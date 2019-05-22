#include "car.h"

Car::Car()
{}

Car::Car(string brand,int weight)
{
    this->brand = brand;
    this->weight = weight;
}

Car::~Car()
{}

void Car::setBrand(string brand)
{
    this->brand = brand;
}

string Car::getBrand()
{
    return brand;
}

void Car::setWeight(int weight)
{
    this->weight = weight;
}

int Car::getWeight()
{
    return weight;
}

void Car::displayCar()
{
    cout << "Brand:" << brand << endl;
    cout << "Weight:" <<weight <<  "ton" << endl;
}