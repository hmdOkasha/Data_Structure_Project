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
    int getDay();
    int getHour();
    bool equals(Time);
    int toInt();
    Time toTime(int t);
    void printTime();
};

Time::Time(int d, int h)
{
    day = d;
    hour = h;
}

void Time::setTime(int d, int h)
{
    day = d;
	if (h >= 0 && h < 24)
    hour = h;
    else if (h >= 24)
    {
        while (h >= 24)
        {
            day++;
            h = h - 24;
            hour = h;
        }
    }
}

bool Time::equals(Time otherTime)
{
    if (day == otherTime.day &&
        hour == otherTime.hour)
        return true;
    else
        return false;
}

int Time::toInt()
{
	return 24 * day + hour;
}

Time Time::toTime(int t)
{
    Time newTime;
    newTime.day = t / 24;
    newTime.hour = t % 24;
    return newTime;
}
void Time::printTime()
{
    cout <<"Current Time (Day:Hour) :" << "(" << day << ":" << hour << ")";
}

int Time::getDay()
{
    return day;
}
int Time::getHour()
{
    return hour;
}
