#pragma once
#include "LinkedQueue.h"
#include "Cargo.h"
#include "Trucks.h"
class NormalTrucks : public Trucks
{
private:
	TruckType typeOfTruck;
	int truckCapacity;
	Time maintenanceTime;
	int speed;
	Time deliveryInterval;
	int furthestCargoDist;
	int sumLoadUnload;

public:
	LinkedQueue<Cargo*> loadedNormalCargo = LinkedQueue<Cargo*>();
	NormalTrucks()
	{
		setID(0);
		typeOfTruck = Normal_Truck;
		truckCapacity = 0;
		maintenanceTime.setTime(0 ,0);
		speed = 0;
		furthestCargoDist = getFurthestCargoDist();
		sumLoadUnload = getSumLoadUnload();
	}
	NormalTrucks(int id, TruckType TT, int TC, Time MT, int Speed)
	{
		setID(id);
		typeOfTruck = TT;
		truckCapacity = TC;
		maintenanceTime = MT;
		speed = Speed;
		furthestCargoDist = getFurthestCargoDist();
		sumLoadUnload = getSumLoadUnload();
	}
	void setTruckType(TruckType type)
	{
		typeOfTruck = type;
	}
	void setTruckCapacity(int capacity)
	{
		truckCapacity = capacity;
	}
	void setMaintenanceTime(Time maintT)
	{
		maintenanceTime = maintT;
	}
	void setSpeed(int Speed)
	{
		speed = Speed;
	}
	void setDeliveryInterval(Time DI)
	{
		deliveryInterval = DI;
	}

	TruckType getTruckType()
	{
		return typeOfTruck;
	}
	int getTruckCapacity()
	{
		return truckCapacity;
	}
	Time getMaintenanceTime()
	{
		return maintenanceTime;
	}
	int getIntMT()
	{
		return maintenanceTime.toInt();
	}
	int getSpeed()
	{
		return speed;
	}
	Time getDeliveryInterval()
	{
		int x = getFurthestCargoDist();
		int DI = x / getSpeed() + sumLoadUnload + furthestCargoDist / getSpeed();

		deliveryInterval = deliveryInterval.toTime(DI);
		return deliveryInterval;
	}
	int getIntDI()
	{
		int x = getFurthestCargoDist();
		int DI = x / getSpeed() + sumLoadUnload + furthestCargoDist / getSpeed();
		return DI;
	}

	//void calculateFurthestCargo()
	//{
	//	//traverse the queue comparing cargo.distance and returning a furthest distance
	//	int furthest = 0;
	//	Cargo* c;
	//	for(int i = 0; i < getTruckCapacity(); i++)
	//	{
	//		loadedNormalCargo.dequeue(c);
	//		int x = c->getDeliveryDistance();
	//		if (x > furthest)
	//			furthest = x;
	//		loadedNormalCargo.enqueue(c);
	//	}
	//	furthestCargoDist = furthest;
	//}

	int getFurthestCargoDist()
	{
		int furthest = 0;
		Cargo* c;
		if (!loadedNormalCargo.isEmpty())
		{
			for (int i = 0; i < getTruckCapacity(); i++)
			{
				loadedNormalCargo.dequeue(c);
				int x = c->getDeliveryDistance();
				if (c->getDeliveryDistance() == NULL)
					return 0;
				if (x > furthest)
					furthest = x;
				loadedNormalCargo.enqueue(c);
			}
			furthestCargoDist = furthest;
			return furthestCargoDist;
		}
		return 0;
	}

	/*void calculatesumLoadUnload()
	{
		Cargo* c;
		int sum = 0;
		for (int i = 0; i < getTruckCapacity(); i++)
		{
			loadedNormalCargo.dequeue(c);
			sum = sum + c->getIntLULT();
			loadedNormalCargo.enqueue(c);
		}
		sumLoadUnload = sum;
	}*/
	int getSumLoadUnload()
	{
		Cargo* c;
		int sum = 0;
		if (!loadedNormalCargo.isEmpty())
		{
			for (int i = 0; i < getTruckCapacity(); i++)
			{
				loadedNormalCargo.dequeue(c);
				if (c->getIntLULT() == NULL)
					return 0;
				sum = sum + c->getIntLULT();
				loadedNormalCargo.enqueue(c);
			}
			sumLoadUnload = sum;
			return sumLoadUnload;
		}
		return 0;
	}
};

