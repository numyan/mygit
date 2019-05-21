#include "head.h"

int main(int argc,char** argv)
{
    car benz(4,"Benz",999999,black);
    car BMW;
    BMW.CarAdvertise();
    benz.CarAdvertise();

    return 0;
}