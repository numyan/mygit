#include <iostream>
using namespace std;

#include <cstdio>
#include <cstdlib>
#include <cstring>

class Example
{
private:
    int x;
    static int y;
public:
    Example(int y);
    void display();
    static void fun();
};

Example::Example(int x):
x(x)
{}

void Example::display()
{
    cout << x << endl << y <<endl;
}

void Example::fun()
{
    cout << y << endl;
}

int Example::y = 5;

int main(int argc,char* argv[])
{
    Example ex(5);
    ex.display();
}