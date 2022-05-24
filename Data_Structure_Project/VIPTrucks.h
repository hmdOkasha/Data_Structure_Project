#pragma once
#include "Cargo.h"
#include "LinkedQueue.h"
#include "Trucks.h"
class VIPTrucks :  public Trucks
{
private:
	TruckType typeOfTruck;
	int truckCapacity;
	Time maintenanceTime;
	int speed;
	Time deliveryInterval;
	int furthestCargoDist;
	int sumLoadUnload;
	int highestCost;
	int minPrTime;


public:
	LinkedQueue<Cargo*> loadedVIPCargo = LinkedQueue<Cargo*>();
	VIPTrucks()
	{
		setID(0);
		typeOfTruck = VIP_Truck;
		truckCapacity = 0;
		maintenanceTime.setTime(0, 0);
		speed = 0;
		furthestCargoDist = getFurthestCargoDist();
		sumLoadUnload = getSumLoadUnload();
	}
	VIPTrucks(int id, TruckType TT, int TC, Time MT, int Speed)
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

		deliveryInterval.toTime(DI);
		return deliveryInterval;
	}
	int getIntDI()
	{
		int x = getFurthestCargoDist();
		int DI = x / getSpeed() + sumLoadUnload + furthestCargoDist / getSpeed();
		return DI;
	}

	int getFurthestCargoDist()
	{
		int furthest = 0;
		Cargo* c;
		if (!loadedVIPCargo.isEmpty())
		{
			for (int i = 0; i < getTruckCapacity(); i++)
			{
				loadedVIPCargo.dequeue(c);
				int x = c->getDeliveryDistance();
				if (c->getDeliveryDistance() == NULL)
					return 0;
				if (x > furthest)
					furthest = x;
				loadedVIPCargo.enqueue(c);
			}
			furthestCargoDist = furthest;
			return furthestCargoDist;
		}
		return 0;
	}

	
	int getSumLoadUnload()
	{
		Cargo* c;
		int sum = 0;
		if (!loadedVIPCargo.isEmpty())
		{
			for (int i = 0; i < getTruckCapacity(); i++)
			{
				loadedVIPCargo.dequeue(c);
				if (c->getIntLULT() == NULL)
					return 0;
				sum = sum + 2*c->getIntLULT();
				loadedVIPCargo.enqueue(c);
			}
			sumLoadUnload = sum;
			return sumLoadUnload;
		}
		return 0;
	}

	int mostCost()
	{
		int max = 0;
		Cargo* c;
		if (!loadedVIPCargo.isEmpty())
		{
			for (int i = 0; i < getTruckCapacity(); i++)
			{
				loadedVIPCargo.dequeue(c);
				int x = c->getCost();
				if (c->getCost() == NULL)
					return 0;
				if (x > max)
					max = x;
				loadedVIPCargo.enqueue(c);
			}
			highestCost = max;
			return highestCost;
		}
		return 0;
	}

	int minPrepTime()
	{
		int min = 100000;
		Cargo* c;
		if (!loadedVIPCargo.isEmpty())
		{
			for (int i = 0; i < getTruckCapacity(); i++)
			{
				loadedVIPCargo.dequeue(c);
				int x = c->getIntPT();
				if (c->getIntPT() == NULL)
					return 0;
				if (x < min)
					min = x;
				loadedVIPCargo.enqueue(c);
			}
			minPrTime = min;
			return minPrTime;
		}
		return 0;
	}

	int getHighestPriID()
	{
		//VIPpriority = (max distance / cargo distance) * 100 + (2 * cost / max cost) * 100 + (min prep time / prep time) * 100
		Cargo* c;
		int cargoPriority;
		int maxPri = 0;
		int idMaxPri;
		if (!loadedVIPCargo.isEmpty())
		{
			for (int i = 0; i < truckCapacity; i++)
			{
				loadedVIPCargo.dequeue(c);
				cargoPriority = (furthestCargoDist / c->getDeliveryDistance()) * 100 + 2 * (c->getCost() / highestCost) + (minPrepTime() / c->getIntPT());
				c->setPriority(cargoPriority);
				if (cargoPriority > maxPri)
				{
					maxPri = cargoPriority;
					idMaxPri = c->getID();
				}
				loadedVIPCargo.enqueue(c);
			}
		}
		return idMaxPri;
	}

};

