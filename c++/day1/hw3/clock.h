#ifndef _CLOCK_H_
#define _CLOCK_H_

#include <iostream>

using namespace std;

#include <unistd.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>

class Clock
{
private:
    int hour;
    int min;
    int sec;
public:
    Clock();
    Clock(int _hour,int _min,int _sec);
    ~Clock();

    void setHour(int _hour);
    int getHour();

    void setMin(int _min);
    int getMin();

    void setSec(int _sec);
    int getSec();

    void timing();
    void displayClock();
    void runClock();
};

#endif