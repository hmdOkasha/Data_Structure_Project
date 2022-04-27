#pragma once
#include <iostream>
#include "Events.h"
#include "company.h"
#include "Cargo.h"
#include "Time.h"
#include "QueueADT.h"
#include "PriorityQ.h"
#include "PriorityQueue.h"
#include "LinkedQueue.h"
using namespace std;
class Promotion:Events
{
	Time Execute()
	{}
	Time Execute(LinkedQueue<Cargo>normal, LinkedQueue<Cargo>VIP, Time event_time)
	{
		Cargo c;
		normal.peek(c);
		if (c.getTypeOfCargo() == Normal)
		{
			VIP.enqueue(c);
			normal.dequeue(c);
			return event_time;
		}
	}
};