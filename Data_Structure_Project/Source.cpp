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
		
		if (simTime->getHour() != 1 && (simTime->getHour() - 1) % 5 == 0)
		{
			if (!com->waitingNormalCargo.isEmpty() || !com->waitingSpecialCargo.isEmpty() || !com->waitingVIPCargo.isEmpty())
			com->moveToDelivered();
		}

		ui->printCurrentTime(simTime);
		ui->outputCargos(com, "Waiting Cargos : ", true);
		//
		ui->outputDelCargos(com, "Delivered Cargos : ", false);


		simTime->setTime(simTime->getDay(), simTime->getHour() + 1);
	}

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


	//}
	//else if (type == 2)
	//{
	//	char temp;
	//	cout << "wait for phase 2 :)";
	//	cin >> temp;

	//}
	//else if (type == 3)
	//{
	//	char temp;
	//	cout << "wait for phase 2 :(";
	//	cin >> temp;
	//}
}
