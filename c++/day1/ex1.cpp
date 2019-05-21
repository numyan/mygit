#include <iostream>

using namespace std;

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

int main (int argc,char* argv[])
{
    double x = 0.0;
    double y = 0.0;
    double result = 0.0;
    char c = '\0';


    cout << "Please input two number and a compute symbol:" << endl;
    cin >> x >> c >> y;

    switch (c)
    {
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
            if(y > -0.000001 && y < 0.000001)
            {
                throw string("除数不能为0");
            }
            result = x / y;
            break;
        default:
            cout << "error symbol" << endl;
            break;
    }catch(const string& err)
    {
        
    };
    cout << "result：";
    cout << result << endl;

    return 0;
}