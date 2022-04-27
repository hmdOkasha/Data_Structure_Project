#pragma once
#include <iostream>
#include "Events.h"
#include "company.h"
#include "Cargo.h"
#include "Time.h"
#include "QueueADT.h"
#include "PriorityQ.h"
#include "LinkedQueue.h"
using namespace std;
class Cancellation
{
	Time Execute()
	{}
	Time Execute(LinkedQueue<Cargo>delivered, LinkedQueue<Cargo>cancelled, Time event_time)
	{
		Cargo c;
		if (!delivered.isEmpty() && c.getTypeOfCargo() == Normal_Cargo)
		{
			delivered.peek(c);
			cancelled.enqueue(c);
			delivered.dequeue(c);
			return event_time;
		}
	}
};