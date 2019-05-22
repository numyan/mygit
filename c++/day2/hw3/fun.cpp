#include "singleton.h"

SingleTon* SingleTon::instance = NULL;

SingleTon::SingleTon()
{}

SingleTon* SingleTon::getInstance()
{
    if(instance == NULL)
    {
        instance = new SingleTon();
    }
    return instance;
}
