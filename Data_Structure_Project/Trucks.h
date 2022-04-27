#pragma once
#include "Cargo.h"
#include "Time.h"
enum TruckType
{
	VIP_Truck = 1,
	Normal_Truck = 2,
	Special_Truck = 3
};


class Trucks
{
private:
	int ID;
public:
	Trucks()
	{
		ID = 0;
	}
	Trucks(int id)
	{
		ID = id;
	}
	int getID ()
	{
		return ID;
	}
	void setID(int id)
	{
		ID = id;
	}
};

