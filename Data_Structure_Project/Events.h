#pragma once
#include <iostream>
#include "Events.h"
#include "company.h"
#include "Cargo.h"
#include "Time.h"
#include "QueueADT.h"
#include "PriorityQ.h"
#include "PriorityQueue.h"
#include "LinkedQueue.h"
using namespace std;
class Events
{
public:
	virtual Time Execute() = 0;
};

