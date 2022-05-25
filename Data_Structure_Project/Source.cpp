#include <fstream>

#include "Cancellation.h"
#include "Company.h"
#include "Preparation.h"
#include "PrioQ.h"
#include "Promotion.h"
#include "UI.h"


class Events;

int main()
{
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

	int countHN = 0;
	int countDN = 0;
	int countSH = 0;
	int countSD = 0;
	int countVH = 0;
	int countVD = 0;
	int Cjourney = 0;
	int cjNormal = 0;
	int cjSpecial = 0;
	int cjVIP = 0;
	bool bNormal = true;
	bool bSpecial = true;
	bool bVIP = true;
	ifstream inFile;
	UI* ui = new UI;
	
	Company* com = new Company;
	int type = ui->chooseMode();
	Time* simTime = new Time(0, 0);
	
	PrioQ<Events*> EventsQueue;

	// temporary event pointer
	Events* tempEvent = NULL;

	// Get input file from user
	string inputFilePath = ui->enterInput("Please enter input file name");

	// Read input file
	inFile.open(inputFilePath);
	inFile >> normalCount >> specialCount >> VIPCount; //get truck count
	inFile >> normalSpeed >> specialSpeed >> VIPspeed; //get truck speeds
	inFile >> normalCapacity >> specialCapacity >> VIPCapacity; //get truck capacities
	inFile >> journeyCount >> maintTimeNormal >> maintTimeSpecial >> maintTimeVIP; //get maintenance info
	inFile >> autoPromotion >> maxWaitTime;//get autoP & maxW


	// Initialize Trucks
	for(int i = 0; i < normalCount; i++)
	{
		NormalTrucks* nt;
		nt = new NormalTrucks(i+1, Normal_Truck, normalCapacity, maintTimeNormal, normalSpeed);
		com->normalTrucks.enqueue(nt);
	}
	for (int i = 0; i < specialCount; i++)
	{
		SpecialTrucks* st;
		st = new SpecialTrucks(i+1, Special_Truck, specialCapacity, maintTimeSpecial, specialSpeed);
		com->specialTrucks.enqueue(st);
	}
	for (int i = 0; i < VIPCount; i++)
	{
		VIPTrucks* vt;
		vt = new VIPTrucks(i+1, VIP_Truck, VIPCapacity, maintTimeVIP, VIPspeed);
		com->vipTrucks.enqueue(vt);
	}


	inFile >> eventNum;

	for (int i = 0; i < eventNum; i++)
	{
		inFile >> eventType;
		switch (eventType)
		{
		case ('R'):
			inFile >> cargoType >> eventDay >> red >> eventHour >> ID >> distance >> loadTime >> cost;
			eventTime.setTime(eventDay, eventHour);
			tempEvent = new Preparation(ID, eventTime, com, cargoType, distance, loadTime, cost);
			break;

		case('X'):
			inFile >> eventDay >> red >> eventHour >> ID;
			eventTime.setTime(eventDay, eventHour);
			tempEvent = new Cancellation(ID, eventTime, com);
			break;

		case ('P'):
			inFile >> eventDay >> red >> eventHour >> ID >> extraCost;
			eventTime.setTime(eventDay, eventHour);
			tempEvent = new Promotion(ID, eventTime, com, extraCost);
			break;

		}

		EventsQueue.enqueueAscending(tempEvent, eventTime.toInt());
	}

	PrioQNode<Events*> Node;
	while (!EventsQueue.isEmpty())
	{
		EventsQueue.peek(Node);

		// check event list for events at current sim time and execute them
		if (Node.getItem()->getTime().equals(*simTime))
		{
			Node.getItem()->Execute();
			EventsQueue.dequeue(Node);
		}

		if (type == 1)
			ui->getUserInput();
		else if (type == 2)
		{
			// wait 1 second
		}
		else
		{
			// do nothing and let time pass
		}

		/*	if (simTime->getHour() != 1 && (simTime->getHour() - 1) % 5 == 0)
			{
				if (!com->waitingNormalCargo.isEmpty() || !com->waitingSpecialCargo.isEmpty() || !com->waitingVIPCargo.isEmpty())
				com->moveToDelivered();
			}*/

		ui->printCurrentTime(simTime);
		ui->outputCargos(com);
		//
		ui->outputDelCargos(com);


		simTime->setTime(simTime->getDay(), simTime->getHour() + 1);
		Cargo* cn;
		Cargo* cs;
		Cargo* cv;
		if (bNormal)
		{
			com->waitingNormalCargo.peek(cn);
			if (cn != NULL)
			{
				int HN = (cn->getLoadAndUnloadTime()).getHour();
				int DN = (cn->getLoadAndUnloadTime()).getDay();
				if (DN == 0)
				{
					if (HN == countHN)
					{
						com->loadNormal();
						cjNormal++;
						countHN = 0;
					}
					else
						countHN++;
				}
				else
				{
					countHN++;
					if (countHN == 24)
					{
						countDN++;
						countHN = 0;
					}
					if (DN == countDN)
					{
						com->loadNormal();
						cjNormal++;
						countDN = 0;
						countHN = 0;
					}
				}
			}
			if (cjNormal == journeyCount)
			{
				bNormal == false;
				cjNormal = maintTimeNormal;
			}
		}
		else
		{
			cjNormal--;
			if (cjNormal == 0)
				bNormal = true;
		}
		if (bSpecial)
		{
			com->waitingSpecialCargo.peek(cs);
			if (cs != NULL)
			{
				int SH = cs->getLoadAndUnloadTime().getHour();
				int SD = cs->getLoadAndUnloadTime().getDay();
				if (SD == 0)
				{
					if (SH == countSH)
					{
						com->loadNormal();
						cjSpecial++;
						countSH = 0;
					}
					else
						countSH++;
				}
				else
				{
					countSH++;
					if (countSH == 24)
					{
						countSD++;
						countSH = 0;
					}
					if (SD == countSD)
					{
						com->loadNormal();
						cjSpecial++;
						countSD = 0;
						countSH = 0;
					}
				}
			}
			if (cjSpecial == journeyCount)
			{
				bSpecial = false;
				cjSpecial = maintTimeSpecial;
			}
		}
		else
		{
			cjSpecial--;
			if (cjSpecial == 0)
				bSpecial = true;
		}
		if (bVIP)
		{
			com->waitingVIPCargo.peek(cv);
			if (cv != NULL)
			{
				int VH = cn->getLoadAndUnloadTime().getHour();
				int VD = cn->getLoadAndUnloadTime().getDay();
				if (VD == 0)
				{
					if (VH == countVH)
					{
						com->loadNormal();
						cjVIP++;
						countVH = 0;
					}
					else
						countVH++;
				}
				else
				{
					countVH++;
					if (countVH == 24)
					{
						countVD++;
						countVH = 0;
					}
					if (VD == countVD)
					{
						com->loadNormal();
						cjVIP++;
						countVD = 0;
						countVH = 0;
					}
				}
			}
			if (cjVIP == journeyCount)
			{
				bVIP = false;
				cjVIP = maintTimeVIP;
			}
		}
		else
		{
			cjVIP--;
			if (cjVIP == 0)
				bVIP = true;
		}
	}
<<<<<<< HEAD
	//if (type == 1)
	//{
	//	while (1)
	//	{
	//		inFile >> eventType;
	//		switch (eventType)
	//		{
	//		case ('R'):
	//			inFile >> cargoType >> eventDay >> red >> eventHour >> ID >> distance >> loadTime >> cost;
	//			eventTime.setTime(eventDay, eventHour);
	//			if (eventTime.equals(*simTime))
	//				p->Execute(&waitingNormalCargo, &waitingSpecialCargo, &waitingVIPCargo, eventTime, loadTime, cargoType, ID, distance, cost);
	//		case('X'):
	//			inFile >> eventDay >> red >> eventHour >> ID;
	//			eventTime.setTime(eventDay, eventHour);
	//			if (eventTime.equals(*simTime))
	//				can->Execute(&deliveredNormalCargo, &cancelledCargo);
	//		case ('P'):
	//			inFile >> eventDay >> red >> eventHour >> ID >> extraCost;
	//			eventTime.setTime(eventDay, eventHour);
	//			if (eventTime.equals(*simTime))
	//				pr->Execute(&waitingNormalCargo, &waitingVIPCargo);
	//		}
	//		ui->getUserInput();
	//		simTime->setTime(simTime->getDay(), simTime->getHour() + 1);
	//		ui->printCurrentTime(simTime);
	//		ui->outputCargos(waitingNormalCargo, waitingSpecialCargo, waitingVIPCargo, "Waiting Cargos : ", true);
	//		ui->outputCargos(deliveredNormalCargo, deliveredSpecialCargo, deliveredVIPCargo, "Delivered Cargos : ", false);
	//	}
	//	//while (simTime->getHour()  != 1 && (simTime->getHour() - 1) % 5 == 0)
	//	//{
	//	//	com->moveToDelivered(&waitingNormalCargo, &waitingSpecialCargo, &waitingVIPCargo, &deliveredNormalCargo, &deliveredSpecialCargo, &deliveredVIPCargo);
	//	//}
=======

>>>>>>> 6ee396e0611caf3d3672325303645bbc0fd01a4b

}
