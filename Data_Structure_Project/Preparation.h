#pragma once
#include<iostream>
#pragma once
#include "Events.h"
#include "company.h"
#include "Cargo.h"
#include "Time.h"
#include "QueueADT.h"
#include "PriorityQ.h"
#include "LinkedQueue.h"
using namespace std;
class Preparation :Events
{
public:
	Time Execute()
	{}
	Time Execute(LinkedQueue<Cargo>waiting_list,Time P_T, Time L_T , cargoType c_t , int dist, int cost, Time event_time)
	{
		Cargo c;
		c.setCost(cost);
		c.setDeliveryDistance(dist);
		c.setLoadAndUnloadTime(L_T);
		c.setPreparationTime(P_T);
		c.setTypeOfCargo(c_t);
		c.setID(waiting_list.QueueCount(waiting_list) + 1);
		waiting_list.enqueue(c);
		return event_time;
	}

};