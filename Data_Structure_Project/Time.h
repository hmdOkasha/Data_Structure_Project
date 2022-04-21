#pragma once
#include<iostream>
#include<iomanip>
using namespace std;

class Time
{
private:
    int day;
    int hour;
public:
    Time(int d = 0, int h = 0);
    void setTime(int d = 0, int h = 0);
    bool equals(Time);
};

Time::Time(int d, int h)
{
    day = d;
    hour = h;
}

void Time::setTime(int d, int h)
{
    day = d;
    hour = h;
}

bool Time::equals(Time otherTime)
{
    if (day == otherTime.day &&
        hour == otherTime.hour)
        return true;
    else
        return false;
}