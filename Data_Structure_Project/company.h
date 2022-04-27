#pragma once
#include "Time.h"
#include "Trucks.h"
#include "VIPTrucks.h"
#include "SpecialTrucks.h"
#include "NormalTrucks.h"
#include "Cargo.h"
#include "LinkedList.h"
#include "LinkedQueue.h"
#include "Node.h"
#include "PriorityQ.h"
#include "QueueADT.h"
#include <fstream>
class Company
{
private:
	Time deliveryInterval;
	int furthestCargoDistance;
	Time cargoWaitTime;
	Time cargoDeliveryTime;
	int truckUtilization;

public:
	Time calculateDI()
	{
		
	}
	int calculateFurthestCargo()
	{

	}
	Time calculateWaitTime()
	{
		/*Preparation is event time to be supplied from file*/
	}
	Time calculateCDT()
	{
		
	}
	int calculateTU()
	{
		
	}
};


int main()
{
	int type = -1;
	while (type <= 0 || type >= 3)
	{
		cout << "please enter 1-3 to select the mode" << endl;
		cout << "1 = Interactive Mode" << endl
			<< "2 = Step-By-Step Mode" << endl
			<< "3 = Silent Mode"<< endl;
		cin >> type;
	}
	
	Time* simTime = new Time(0, 0);
	while(type == 1)
	{










	}
	while(type == 2)
	{
		
	}
	while(type == 3)
	{
		
	}
}