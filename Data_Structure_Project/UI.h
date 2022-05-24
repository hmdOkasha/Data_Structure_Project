#pragma once
#include "iostream"
using namespace std;
#include"Cargo.h"
#include"Time.h"
#include"LinkedQueue.h"
#include"LinkedList.h"
#include"PriorityQ.h"
#include "Time.h"
#include "Company.h"

class UI
{
public:

	UI()
	{

	}

	void printCargo(LinkedQueue<Cargo*> Q)
	{
		Cargo* K;
		while (Q.dequeue(K))
		{
			if (Q.isEmpty())
				cout << K->getID() << "";
			else
				cout << K->getID() << ",";
		}
	}

	void printVIPCargo(PriQ<Cargo*> Q)
	{
		Node<Cargo*>* K = new Node<Cargo*>;
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

	void printCurrentTime(Time* CT)
	{
		cout << "Current Time (Day:Hour) :" << "(" << CT->getDay() << ":" << CT->getHour() << ")" << endl;
	}

	void outputCargos(Company *company, string message, bool flag)
	{		
		int ncount = company->waitingNormalCargo.QueueCount();
		int scount = company->waitingSpecialCargo.QueueCount();
		int VIPcount = company->waitingVIPCargo.QueueCount();
		cout << ncount + scount + VIPcount << " " << message << ": ";
		cout << "[";
		company->waitingNormalCargo.PrintQueue();
		cout << "] ";
		cout << "(";
		company->waitingSpecialCargo.PrintQueue();
		cout << ") ";
		cout << "{";
		company->waitingVIPCargo.PrintQueue();
		cout << "}" << endl;
		if (flag) {
			cout << "----------------------------------------------------" << endl;
		}
	}


	void outputDelCargos(Company* company, string message, bool flag)
	{
		int ncount = company->deliveredNormalCargo.QueueCount();
		int scount = company->deliveredSpecialCargo.QueueCount();
		int VIPcount = company->deliveredVIPCargo.QueueCount();
		cout << ncount + scount + VIPcount << " " << message << ": ";
		cout << "[";
		company->deliveredNormalCargo.PrintQueue();
		cout << "] ";
		cout << "(";
		company->deliveredSpecialCargo.PrintQueue();
		cout << ") ";
		cout << "{";
		company->deliveredVIPCargo.PrintQueue();
		cout << "}" << endl;
		if (flag) {
			cout << "----------------------------------------------------" << endl;
		}
	}

	void getUserInput()
	{
		cout << "please click the enter key to progress to next time step" << endl;
		cin.get();
	}

	string enterInput(const char* prompt)
	{
		string input;

		cout << prompt << endl;

		cin >> input;

		return input;
	}
};

#pragma once

	//void outputCargos(LinkedQueue<Cargo*>normal, LinkedQueue<Cargo*>special, LinkedQueue<Cargo*>VIP, string message, bool flag) {
	//	int ncount = normal.QueueCount();
	//	int scount = special.QueueCount();
	//	int VIPcount = VIP.QueueCount();
	//	cout << ncount + scount + VIPcount << " " << message << ": ";
	//	cout << "[";
	//	normal.PrintQueue();
	//	cout << "] ";
	//	cout << "(";
	//	special.PrintQueue();
	//	cout << ") ";
	//	cout << "{";
	//	VIP.PrintQueue();
	//	cout << "}" << endl;
	//	if (flag) {
	//		cout << "----------------------------------------------------" << endl;
	//	}
	//}