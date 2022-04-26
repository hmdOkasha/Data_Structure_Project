<<<<<<< HEAD
#pragma once
#include <iostream>
#include "Time.h"
using namespace std;
class Events
{
private:
	Time event_time;

public:
	virtual void Execute() = 0;
	void get_event_time(Time& t)
	{
		t = event_time;
	}
};
=======
#pragma once
#include <iostream>
#include "Time.h"
using namespace std;
class Events
{
private:
	Time event_time;

public:
	virtual void Execute() = 0;
	void get_event_time(Time& t)
	{
		t = event_time;
	}
};
>>>>>>> 19cb1d8cd43bc3dfd3bc576488233ee2cbec7260
