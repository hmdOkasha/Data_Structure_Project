#pragma once
#include "iostream"
using namespace std;
#include"Cargo.h"
#include"Time.h"
#include"LinkedQueue.h"
#include"LinkedList.h"
#include"PriorityQ.h"
#include"Time.h"

void printCargo(LinkedQueue<Cargo *> Q)
{
	Cargo* K;
	while(Q.dequeue(K))
	{
		if (Q.isEmpty())
			cout << K->getID() << "";
		else
			cout << K->getID() << ",";
	}
}

void printVIPCargo(PriQ<Cargo *> Q)
{
	Node<Cargo*> *K;
	while (Q.dequeue(K))
	{
		if (Q.isEmpty())
			cout << K->getItem()->getID() << "";
		else
			cout << K->getItem()->getID() << ",";
	}
}

int chooseMode() {
	int num;
	cout << "Please choose the mode you want to run the program in:" << endl;
	cout << "Press 1 for Interactive mode , 2 for StepByStep mode , 3 for silent mode" << endl;
	cin >> num;
	while (num < 1 || num >3) {
		cout << "Invalid number, Please select 1 or 2 or 3 to run the program" << endl;
		cin >> num;
	}
	return num;
}

void printCurrentTime(Time CT)
{
	cout << "Current Time (Day:Hour) :" << "(" << CT.getDay(CT) << ":" << CT.getHour(CT) << ")";
}

void outputCargos(LinkedQueue<Cargo*>normal, LinkedQueue<Cargo*>special, PriQ<Cargo*>VIP,string message,bool flag) {
	int ncount = normal.QueueCount(normal);
	int scount = special.QueueCount(special);
	int VIPcount = VIP.PrioQueueCount(VIP);
	cout << ncount + scount + VIPcount << " " << message << ": ";
	cout << "[";
	printCargo(normal);
	cout << "] ";
	cout << "(";
	printCargo(special);
	cout << ") ";
	cout << "{";
	printVIPCargo(VIP);
	cout << "}" << endl;
	if (flag) {
		cout << "----------------------------------------------------" << endl;
		flag = true;
	}
}

//void outputDelivered(LinkedQueue<Cargo*> normalDelivered, LinkedQueue<Cargo*> specialDelivered, PriQ<Cargo*> VIPDelivered, string message, bool flag)
//{
//	int normaldelCount = normalDelivered.QueueCount(normalDelivered);
//	int specialdelCount = specialDelivered.QueueCount(specialDelivered);
//	int VIPdelCount = VIPDelivered.PrioQueueCount(VIPDelivered);
//	cout << normaldelCount + specialdelCount +VIPdelCount << " " << message << ": ";
//	cout << "[";
//	printCargo(normalDelivered);
//	cout << "] ";
//	cout << "(";
//	printCargo(specialDelivered);
//	cout << ") ";
//	cout << "{";
//	printVIPCargo(VIPDelivered);
//	cout << "}" << endl;
//	if (flag) {
//		cout << "----------------------------------------------------" << endl;
//		flag = true;
//	}
//	
//}
