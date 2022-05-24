#pragma once
#include "Time.h"
using namespace std;

enum cargoType
{
	VIP_Cargo = 1,
	Normal_Cargo = 2,
	Special_Cargo = 3,
};

class Cargo 
{
private:
	int ID;
	Time preparationTime;
	Time loadAndUnloadTime;
	cargoType typeOfCargo;
	int deliveryDistance;
	int cost;
public:
	Cargo()
	{
		preparationTime.setTime(0, 0);
		loadAndUnloadTime.setTime(0, 0);
		typeOfCargo = Normal_Cargo;
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
		return preparationTime.toInt();
	}
	Time getLoadAndUnloadTime()
	{
		return loadAndUnloadTime;
	}
	int getIntLULT()
	{
		return loadAndUnloadTime.toInt();
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