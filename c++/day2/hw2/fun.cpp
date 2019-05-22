#include "head.h"

String::String(const char* str )
{
    _data = new char[strlen(str) + 1]();
    strcpy(_data,str);
    str = NULL;
}

String::String(const String &rhs)
{
    _data = rhs._data;
}

String::~String()
{
    delete _data;
    _data = NULL;
}

const char* String::data()const
{
    return _data;
}