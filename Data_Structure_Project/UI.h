#pragma once
#include "iostream"
using namespace std;
#include"Cargo.h"
#include"Time.h"
#include"LinkedQueue.h"
#include"LinkedList.h"
#include"PriorityQ.h"

enum UI_MODE
{
	Interactive,
	StepByStep,
	Silent
};

int chooseMode() {
	int num;
	cout << "Please choose the mode you want to run the program in:" << endl;
	cout << "Press 1 for Interactive mode , 2 for StepByStep mode , 3 for silent mode" << endl;
	cin >> num;
	while (num < 1 || num >3) {
		cout << "Invalid number, Please select 1 or 2 or 3 to run the program" << endl;
	}
	return num;
}
void outputWaitingCargos(LinkedQueue<Cargo*>waitingnormal, LinkedQueue<Cargo*>waitingspecial,PriQ<Cargo*>waitingVIP) {
	int x = QueueCount(waitingnormal);
	int y = QueueCount(waitingspecial);
	int z = waitingVIP.PrioQueueCount(waitingVIP);
	cout << "[";
	PrintQueue(waitingnormal);
	cout << "]";
	cout << "(";
	PrintQueue(waitingspecial);
	cout << ")";
	cout << "{";
	waitingVIP.PrintPrioQueue(waitingVIP);
	cout << "}" << endl;
	cout << "----------------------------------------------------" << endl;
}
void outputDeleviredCargos(LinkedQueue<Cargo*>deliverednormal, LinkedQueue<Cargo*>deliveredspecial, PriQ<Cargo*>deliveredVIP) {
	cout << "[";
	PrintQueue(deliverednormal);
	cout << "]";
	cout << "(";
	PrintQueue(deliveredspecial);
	cout << ")";
	cout << "{";
	deliveredVIP.PrioQueueCount(deliveredVIP);
	cout << "}";
}
ifstream f;


