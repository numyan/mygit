#include <iomanip>

#include "clock.h"

Clock::Clock(int _hour,int _min,int _sec):
hour(_hour),
min(_min),
sec(_sec)
{}

Clock::~Clock()
{}

void Clock::setHour(int _hour)
{
    hour = _hour % 24;
}

int Clock::getHour()
{
    setHour(hour);
    return hour;
}

void Clock::setMin(int _min)
{
    hour += min / 60;
    min = _min % 60;
    hour = hour % 24;
}

int Clock::getMin()
{
    setMin(min);
    return min;
}

void Clock::setSec(int _sec)
{
    min += sec / 60;
    sec = _sec % 60;
    hour += min / 60;
    min = min % 60;
    hour = hour % 24;
}

int Clock::getSec()
{
    setSec(sec);
    return sec;
}

void Clock::timing()
{
    sec += 1;
    min += sec / 60; 
    sec = sec % 60; 
    hour += min / 60;
    min = min % 60;
    hour = hour % 24;
}

void Clock::displayClock()
{
    cout << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << min << ":" << setw(2) << setfill('0') << sec << endl;
}

void Clock::runClock()
{
    while(1)
    {
        system("clear");
        displayClock();
        sleep(1);
        timing();  
    }
}