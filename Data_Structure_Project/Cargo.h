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
	int TruckID;
	Time preparationTime;
	Time loadAndUnloadTime;
	Time movetime;
	cargoType typeOfCargo;
	int deliveryDistance;
	int cost;
	int priority;
public:
	Cargo()
	{
		preparationTime.setTime(0, 0);
		loadAndUnloadTime.setTime(0, 0);
		movetime.setTime(0, 0);
		typeOfCargo = Normal_Cargo;
		deliveryDistance = 0;
		cost = 0;
		ID = 0;
		priority = 0;
	}
	Cargo(Time prepTime, Time loadTime, cargoType type, int dist, int cst, int id)
	{
		preparationTime = prepTime;
		loadAndUnloadTime = loadTime;
		typeOfCargo = type;
		deliveryDistance = dist;
		cost = cst;
		ID = id;
		priority = 0;
	}
	void setPreparationTime(Time t)
	{
		preparationTime = t;
	}

	void setLoadAndUnloadTime(Time t)
	{
		loadAndUnloadTime = t;
	}
	void setmoveTime(Time t) {
		movetime = t;
	}
	Time getwaitTime() {
		Time WT;
		WT = movetime - preparationTime;
		return WT;
	}
	Time getcargodeliveryTime() {
		Time CDT;
		Time sum = getwaitTime() + movetime;
		//int hour=deliveryDistance/
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
	Time getmoveTime() {
		return movetime;
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
	int getPriority()
	{
		return priority;
	}
	void setPriority(int pri)
	{
		priority = pri;
	}
	Time calculateWaitTime()
	{
		// this should be in class cargo
		//Preparation time is the time the cargo is created using the preparation event
		//Move time is the time the truck starts to move which is in phase 2
	}
	Time calculateCargoDeliveryTime()
	{
		// this should be in class cargo
		// move time + cargo distance/truck speed + cargo load and unload time
	}
	void setTruckID(int TID) {
		TruckID = TID;
	}
	int getTruckID() {
		return TruckID;
	}
};