#pragma once
#include "Events.h"
#include "Cargo.h"
#include "LinkedQueue.h"

class Promotion : public Events
{
private:

	int ExtraMoney;

public:
	Promotion(int id, const Time& event_time, Company* company, int extra_money)
		: Events(id, event_time, company),
		ExtraMoney(extra_money)
	{
	}

	void Execute()
	{
		Cargo* c;
		if (!getCompany()->waitingNormalCargo.isEmpty())
		{
			getCompany()->waitingNormalCargo.peek(c);
			getCompany()->waitingVIPCargo.enqueue(c);
			getCompany()->waitingNormalCargo.dequeue(c);
		}
	}

	
	int getExtraMoney() const
	{
		return ExtraMoney;
	}

	void setExtraMoney(int extra_money)
	{
		ExtraMoney = extra_money;
	}

};