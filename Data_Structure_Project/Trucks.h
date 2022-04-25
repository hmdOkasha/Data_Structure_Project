#pragma once
#include "Time.h"
enum TruckType
{
	VIP = 1,
	Normal = 2,
	Special = 3
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

