#pragma once
#include<fstream>
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
	int noLoadingTrucks;

public:

	//cargo list initialization
	LinkedQueue<Cargo*> waitingNormalCargo = LinkedQueue<Cargo*>();
	LinkedQueue<Cargo*> waitingSpecialCargo= LinkedQueue<Cargo*>();
	LinkedQueue<Cargo*> waitingVIPCargo= LinkedQueue<Cargo*>();
	LinkedQueue<Cargo*> deliveredNormalCargo= LinkedQueue<Cargo*>();
	LinkedQueue<Cargo*> deliveredSpecialCargo= LinkedQueue<Cargo*>();
	LinkedQueue<Cargo*> deliveredVIPCargo= LinkedQueue<Cargo*>();
	LinkedQueue<Cargo*> cancelledCargo= LinkedQueue<Cargo*>();
	LinkedQueue<Cargo*> deliveredCargos;

	//truck list initialization
	LinkedQueue<NormalTrucks*> normalTrucks = LinkedQueue<NormalTrucks*>();
	LinkedQueue<VIPTrucks*> vipTrucks = LinkedQueue<VIPTrucks*>();
	LinkedQueue<SpecialTrucks*> specialTrucks = LinkedQueue<SpecialTrucks*>();

	
	int calculateTruckUtilization()
	{
		//total cargos delivered/(truck capacity*total delivery journeys) * (total truck active time/total sim time)
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

	bool canLoad()
	{
		bool h = true;
		NormalTrucks* nt;
		SpecialTrucks* st;
		VIPTrucks* vt;
		normalTrucks.peek(nt);
		specialTrucks.peek(st);
		vipTrucks.peek(vt);

		
		//if all cargo lists are empty
		if (waitingNormalCargo.isEmpty() && waitingSpecialCargo.isEmpty() && waitingVIPCargo.isEmpty())
			return false;

		//case for normal cargos
		if (waitingNormalCargo.QueueCount() < nt->getTruckCapacity())
			return false;

		//case for special cargos
		if (waitingSpecialCargo.QueueCount() < st->getTruckCapacity())
			return false;

		//case for VIP cargos
		if (waitingVIPCargo.QueueCount() < vt->getTruckCapacity())
			return false;

		//If more than 3 trucks are being loaded
		if (noLoadingTrucks >= 3)
			return false;

		return h;
	}

	bool isOffhours(Time sim)
	{
		if (sim.getHour() < 5 || sim.getHour() > 23)
			return true;
		else
			return false;
	}

	void outputFile(ofstream& outfile) {
		outfile << "CDT  CID  PT  WT  TID" << endl;
		int M = deliveredCargos.QueueCount();
		Cargo* x;
		while (deliveredCargos.dequeue(x)) {
			int PT = x->getIntPT();
			int CID = x->getID();
			Time WT = x->getwaitTime();

		}
	}


};
