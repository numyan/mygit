#ifndef CAR_H
#define CAR_H

#include <iostream>
using namespace std;

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

class Car
{
private:
	string brand;
	int weight;
public:
	Car();
	Car(string brand,int weight);
	~Car();

	void  setBrand(string brand);
	string getBrand();

	void setWeight(int weight);
	int getWeight();

	void displayCar();
};


#endif