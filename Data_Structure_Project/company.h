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

	//input file variables:
		//first line
	int normalCount;
	int specialCount;
	int VIPCount;

	//second line
	int normalSpeed;
	int specialSpeed;
	int VIPspeed;

	//third line
	int normalCapacity;
	int specialCapacity;
	int VIPCapacity;

	//fourth line
	int journeyCount;
	int maintTimeNormal;
	int maintTimeSpecial;
	int maintTimeVIP;

	//fifth line
	int autoPromotion;
	int maxWaitTime;

	//event info
	int eventNum;

	//ready event line
	char eventType;
	char cargoType;
	Time eventTime;
	int eventDay;
	int eventHour;
	char red;
	int ID;
	int distance;
	int loadTime;
	int cost;
	int extraCost;

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
	LinkedQueue<Trucks*> movingTrucks = LinkedQueue<Trucks*>();

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
		int sumWT = 0;
		int cWT = 0;
		int avgWT;
		Time avgT, T;
		while (deliveredCargos.dequeue(x)) {
			Time PT = x->getPreparationTime();
			int CID = x->getID();
			Time WT = x->getwaitTime();
			int TID = x->getTruckID();
			sumWT += WT.toInt();
			cWT++;
			avgWT = sumWT / cWT;
			outfile << " " << "  " << CID << "  " << PT.getDay() << ":" << PT.getHour() << "  ";
			outfile << WT.getDay() << ":" << WT.getHour() << "  " << TID << endl;
		}
		T = avgT.toTime(avgWT);
		outfile << "Cargos:" << deliveredCargos.QueueCount() << endl;
		outfile << "Cargo Avg Wait = " << T.getDay() << ":" << T.getHour() << endl;

		outfile << "Trucks: " << normalCount + specialCount + VIPCount << "[N: " << normalCount << ", S: " << specialCount << ",V: " << VIPCount << "]" << endl;


	}


};
