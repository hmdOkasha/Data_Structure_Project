#pragma once
#include <iostream>
#include "Time.h"
#include "Company.h"

using namespace std;

class Events
{
private:

	int ID;
	Time EventTime;
	Company *CurrentCompany;

public:

	Events(int id, const Time event_time, Company* company) : ID(id), EventTime(event_time), CurrentCompany(company)
	{}

	virtual void Execute() = 0;

	int getID();
	void setID(int id);

	Time getTime();
	void setTime(Time time);

	Company* getCompany();
};

inline int Events::getID()
{
	return ID;
}

inline void Events::setID(int id)
{
	ID = id;
}

inline Time Events::getTime()
{
	return EventTime;
}

inline void Events::setTime(Time time)
{
	EventTime = time;
}

inline Company* Events::getCompany()
{
	return CurrentCompany;
}

