#pragma once
#include <iostream>
#include "Events.h"
#include "Company.h"
#include "Cargo.h"
#include "Time.h"
#include "QueueADT.h"
#include "PriorityQ.h"
#include "LinkedQueue.h"
using namespace std;
class Cancellation : public Events
{
public:
	Cancellation(int id, Time& event_time, Company* company)
		: Events(id, event_time, company)
	{
	}

	void Execute()
	{
		Cargo* c = new Cargo;
		if (!getCompany()->waitingNormalCargo.isEmpty())
		{
			getCompany()->waitingNormalCargo.peek(c);
			getCompany()->cancelledCargo.enqueue(c);
			getCompany()->waitingNormalCargo.dequeue(c);
		}
	}

	/*void Execute(LinkedQueue<Cargo*>* delivered_normal, LinkedQueue<Cargo*>* cancelled_normal)
	{
		Cargo* c = new Cargo;
		if (!delivered_normal->isEmpty() && c->getTypeOfCargo() == Normal_Cargo)
		{
			delivered_normal->peek(c);
			cancelled_normal->enqueue(c);
			delivered_normal->dequeue(c);
		}
	}*/
};