#include <iostream>
using namespace std;

#include <cstdio>

class Fraction
{
private:
    int* denominator;
    int* numerator;
public:
    Fraction(int denominator,int numerator);
    ~Fraction();

    void displayFraction();
};

Fraction::Fraction(int denominator,int numerator)
{
    this->denominator = new int(denominator);
    this->numerator = new int(numerator);
}

Fraction::~Fraction()
{
    delete denominator;
    delete numerator;
}

void Fraction::displayFraction()
{
    cout << *this->numerator << "/" << *this->denominator << endl;
}

int main(int argc,char** argv)
{
    Fraction* p = new Fraction(2,1);
    p->displayFraction();
    delete p;

    return 0;
}