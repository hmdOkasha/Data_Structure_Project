#pragma once
#include "Time.h"
#include "Cargo.h"
#include "Trucks.h"
#include "SpecialTrucks.h"
#include "NormalTrucks.h"
#include "VIPTrucks.h"
#include "LinkedQueue.h"

class Company
{
private:
	int VIPpriority;
	int furthestCargoDistance;
	Time cargoWaitTime;
	Time cargoDeliveryTime;
	int truckUtilization;

public:

	//cargo list initialization
	LinkedQueue<Cargo*> waitingNormalCargo = LinkedQueue<Cargo*>();
	LinkedQueue<Cargo*> waitingSpecialCargo= LinkedQueue<Cargo*>();
	LinkedQueue<Cargo*> waitingVIPCargo= LinkedQueue<Cargo*>();
	LinkedQueue<Cargo*> deliveredNormalCargo= LinkedQueue<Cargo*>();
	LinkedQueue<Cargo*> deliveredSpecialCargo= LinkedQueue<Cargo*>();
	LinkedQueue<Cargo*> deliveredVIPCargo= LinkedQueue<Cargo*>();
	LinkedQueue<Cargo*> cancelledCargo= LinkedQueue<Cargo*>();

	//truck list initialization
	LinkedQueue<NormalTrucks*> normalTrucks = LinkedQueue<NormalTrucks*>();
	LinkedQueue<VIPTrucks*> vipTrucks = LinkedQueue<VIPTrucks*>();
	LinkedQueue<SpecialTrucks*> specialTrucks = LinkedQueue<SpecialTrucks*>();

	
	Time calculateDeliveryInterval()
	{
		//furthest cargo / truck speed + Truck capacity*load unload time + return time
	}
	
	Time calculateWaitTime()
	{
		// this should be in class cargo
		//Preparation time is the time the cargo is created using the preparation event
		//Move time is the time the truck starts to move which is in phase 2
	}
	Time calculateCargoDeliveryTime()
	{
		// this should be in class cargo
		// move time + cargo distance/truck speed + cargo load and unload time
	}
	int calculateTruckUtilization()
	{
		//total cargos delivered/(truck capacity*total delivery journeys) * (total truck active time/total sim time)
	}
	int calculateVIPpriority()
	{
		//VIPpriority = (max distance / cargo distance) * 100 + (2 * cost / max cost) * 100 + (min prep time / prep time) * 100
	}
	void moveToDelivered()
	{
		Cargo* c1;
		Cargo* c2;
		Cargo* c3;
		
		if (!waitingNormalCargo.isEmpty())
		{
			waitingNormalCargo.dequeue(c1);
			deliveredNormalCargo.enqueue(c1);
		}

		if(!waitingSpecialCargo.isEmpty())
		{
			waitingSpecialCargo.dequeue(c2);
			deliveredSpecialCargo.enqueue(c2);
		}

		if(!waitingVIPCargo.isEmpty())
		{
			waitingVIPCargo.dequeue(c3);
			deliveredVIPCargo.enqueue(c3);
		}
	}
};
