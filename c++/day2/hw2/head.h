#ifndef _HEAD_H
#define _HEAD_H

#include <iostream>
using namespace std;

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

class String
{
private:
    char* _data;
public:
    String(const char* str );
    String(const String &rhs);
    ~String();
    const char* data() const;
};

#endif
