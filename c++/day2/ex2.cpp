#include <iostream>
using namespace std;

#include <cstdio>
#include <cstdlib>
#include <string>

int main(int argc,char** argv)
{
    string str1 = "hello";
    string str2 = "hello world";
    int i = 0;

    if(str1 == str2)
    {
        cout << "string equal" << endl;
    }
    else if(str1 > str2)
    {
        cout << str1 <<endl;
    }
    else
    {
        cout << str2 << endl;
    }

    while(str1[i] != '\0')
    {
        cout << str1[i] << endl;
        i++;
    }
    
    return 0;
}