#pragma once
#include "iostream"
using namespace std;
#include"Cargo.h"
#include"Time.h"
#include"LinkedQueue.h"
#include"PriorityQueue.h"
#include"LinkedList.h"

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
void outputWaitingCargos(LinkedQueue<Cargo*>waitingnormal, LinkedQueue<Cargo*>waitingspecial,PriorityQueue<Cargo*>waitingVIP) {
	cout << "[";
	PrintQueue(waitingnormal);
	cout << "]";
	cout << "(";
	PrintQueue(waitingspecial);
	cout << ")";
	cout << "{";
	PrintQueue(waitingVIP);
	cout << "}";
}
void outputDeleviredCargos(LinkedQueue<Cargo*>waitingnormal, LinkedQueue<Cargo*>waitingspecial, PriorityQueue<Cargo*>waitingVIP) {
	cout << "[";
	PrintQueue(waitingnormal);
	cout << "]";
	cout << "(";
	PrintQueue(waitingspecial);
	cout << ")";
	cout << "{";
	PrintQueue(waitingVIP);
	cout << "}";
}
ifstream f;


