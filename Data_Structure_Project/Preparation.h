#pragma once
#include<iostream>
#include "Events.h"
#include "Company.h"
#include "Cargo.h"
#include "Time.h"
#include "LinkedQueue.h"

using namespace std;
class Preparation : public Events
{
private:

	char Type;
	int Distance;
	Time LoadTime;
	int Cost;

public:
	Preparation(int id, const Time& event_time, Company* company, char type, int distance, const Time& load_time,
		int cost)
		: Events(id, event_time, company),
		Type(type),
		Distance(distance),
		LoadTime(load_time),
		Cost(cost)
	{
	}

	void Execute()
	{
		
		Cargo* c;
		if (Type == 'N')
			c = new Cargo(getTime(), LoadTime, Normal_Cargo, Distance, Cost, getID());
		else if (Type == 'V')
			c = new Cargo(getTime(), LoadTime, VIP_Cargo, Distance, Cost, getID());
		else
			c = new Cargo(getTime(), LoadTime, Special_Cargo, Distance, Cost, getID());
		if (Type == 'N')
			getCompany()->waitingNormalCargo.enqueue(c);
		else if (Type == 'S')
			getCompany()->waitingSpecialCargo.enqueue(c);
		else
			getCompany()->waitingVIPCargo.enqueue(c);
	}

	/*void Execute(LinkedQueue<Cargo*>* waiting_list_normal, LinkedQueue<Cargo*>* waiting_list_special, LinkedQueue<Cargo*>* waiting_list_vip, Time P_T, Time L_T, char c_t, int id, int dist, int cost)
	{
		Cargo* c;
		if (c_t == 'N')
			c = new Cargo(P_T, L_T, Normal_Cargo, dist, cost, id);
		else if (c_t == 'V')
			c = new Cargo(P_T, L_T, VIP_Cargo, dist, cost, id);
		else
			c = new Cargo(P_T, L_T, Special_Cargo, dist, cost, id);
		if (c_t == 'N')
			waiting_list_normal->enqueue(c);
		else if (c_t == 'S')
			waiting_list_special->enqueue(c);
		else
			waiting_list_vip->enqueue(c);
	}*/

	char getType();
	void setType(char type);

	int getDistance();
	void setDistance(int distance);

	Time getLoadTime();
	void setLoadTime(Time loadTime);

	int getCost();
	void setCost(int cost);
};

inline char Preparation::getType()
{
	return Type;
}

inline void Preparation::setType(char type)
{
	Type = type;
}

inline int Preparation::getDistance()
{
	return Distance;
}

inline void Preparation::setDistance(int distance)
{
	Distance = distance;
}

inline Time Preparation::getLoadTime()
{
	return LoadTime;
}

inline void Preparation::setLoadTime(Time loadTime)
{
	LoadTime = loadTime;
}

inline int Preparation::getCost()
{
	return Cost;
}

inline void Preparation::setCost(int cost)
{
	Cost = cost;
}
#pragma once
