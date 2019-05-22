#include <iostream>
using namespace std;

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

int main()
{
    int a = 1;
    double d = 2.01;

    const int& ri = d;
    const double& rd = d;
    cout << a <<endl;
    cout << rd <<endl;

    return 0;
}