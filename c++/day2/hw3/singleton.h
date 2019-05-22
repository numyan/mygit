#ifndef _SINGLETON_H
#define _SINGLETON_H

#include <iostream>
using namespace std;

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

class SingleTon
{
private:
    SingleTon();
    static SingleTon* instance;
public:
    static SingleTon* getInstance();
};

#endif