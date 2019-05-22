#include <iostream>
using namespace std;

#include <cstdio>
#include <cstdlib>
#include <cstring>

class Single
{
private:
    Single();
    static Single* instance;
public:
    static Single* getInstance()
    {
        if(instance == 0)
        {
            instance = new Single();
        }
        return instance;
    }
};

Single::Single()
{}

Single* Single::instance = NULL;

int main(int argc,char* argv[])
{
    Single* pSingle = Single::getInstance();
    cout << Single::getInstance() <<endl;
}