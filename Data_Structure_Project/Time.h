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
	Time operator -(Time t);
	Time operator+ (Time t);
	Time operator= (Time t);
	bool operator== (Time t);
};
Time Time::operator=(Time t)
{
	t.day = day;
	t.hour = hour;
	return t;
}

bool Time::operator==(Time t)
{
	if (t.day == day && t.hour == hour)
		return true;
	return false;
}
Time Time::operator-(Time t) {
	Time temp;
	if (hour < t.hour) {
		day--;
		int x = hour + 24;
		temp.day = day - t.day;
		temp.hour = x - t.hour;
	}
	else {
		temp.day = day - t.day;
		temp.hour = hour - t.hour;
		return temp;
	}
}

Time Time::operator+(Time t) {
	Time temp;
	temp.day = day + t.day;
	temp.hour = hour + t.hour;
	if (temp.hour >= 24) {
		temp.day++;
		t.hour = t.hour - 24;
	}
	return temp;
}

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
	cout << "Current Time (Day:Hour) :" << "(" << day << ":" << hour << ")";
}

int Time::getDay()
{
	return day;
}
int Time::getHour()
{
	return hour;
}
