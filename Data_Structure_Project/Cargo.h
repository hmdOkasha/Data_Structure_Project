#pragma once
#include "Time.h"
using namespace std;

enum cargoType
{
	VIP = 1,
	Normal = 2,
	Special = 3,
};

class Cargo 
{
private:
	Time preparationTime;
	Time loadAndUnloadTime;
	cargoType typeOfCargo;
	int deliveryDistance;
	int cost;
	int ID;
public:
	Cargo()
	{
		preparationTime.setTime(0, 0);
		loadAndUnloadTime.setTime(0, 0);
		typeOfCargo = Normal;
		deliveryDistance = 0;
		cost = 0;
		ID = 0;
	}
	Cargo(Time prepTime, Time loadTime, cargoType type, int dist, int cst, int id)
	{
		preparationTime = prepTime;
		loadAndUnloadTime = loadTime;
		typeOfCargo = type;
		deliveryDistance = dist;
		cost = cst;
		ID = id;
	}
	void setPreparationTime(Time t)
	{
		preparationTime = t;
	}

	void setLoadAndUnloadTime(Time t)
	{
		loadAndUnloadTime = t;
	}
	void setTypeOfCargo(cargoType type)
	{
		typeOfCargo = type;	
	}
	void setDeliveryDistance(int dist)
	{
		deliveryDistance = dist;
	}
	void setCost(int cst)
	{
		cost = cst;
	}
	void setID(int id)
	{
		ID = id;
	}

	Time getPreparationTime()
	{
		return preparationTime;
	}
	int getIntPT()
	{
		return preparationTime.toInt(preparationTime);
	}
	Time getLoadAndUnloadTime()
	{
		return loadAndUnloadTime;
	}
	int getIntLULT()
	{
		return loadAndUnloadTime.toInt(loadAndUnloadTime);
	}
	cargoType getTypeOfCargo()
	{
		return typeOfCargo;
	}
	int getDeliveryDistance()
	{
		return deliveryDistance;
	}
	int getCost()
	{
		return cost;
	}
	int getID()
	{
		return ID;
	}
	bool is_loaded()
	{
		return true;
	}
};