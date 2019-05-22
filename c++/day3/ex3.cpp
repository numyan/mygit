#include <iostream>
using namespace std;

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

void fun(int& a,int& b,int& c)
{
    if(a < b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    if(a < c)
    {
       int  tmp = a;
        a = c;
        c = tmp;
    }
    if(b < c)
    {
        int tmp = b;
        b = c;
        c =tmp;
    }
}

int main()
{
    int a = 1,b = 2,c = 3;
    fun(a,b,c);

    cout << a << "\t" << b << "\t" << c << "\t" <<endl;
    return 0;
}
