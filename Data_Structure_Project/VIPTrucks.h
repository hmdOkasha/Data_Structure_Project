#pragma once
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
	LinkedQueue<Cargo*> loadedVIPCargo = LinkedQueue<Cargo*>();


public:
	VIPTrucks()
	{
		setID(0);
		typeOfTruck = VIP_Truck;
		truckCapacity = 0;
		maintenanceTime.setTime(0, 0);
		speed = 0;
		deliveryInterval.setTime(0, 0);
	}
	VIPTrucks(int id, TruckType TT, int TC, Time MT, int Speed, Time DI)
	{
		setID(id);
		typeOfTruck = TT;
		truckCapacity = TC;
		maintenanceTime = MT;
		speed = Speed;
		deliveryInterval = DI;
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
		return deliveryInterval;
	}
	int getIntDI()
	{
		return deliveryInterval.toInt();
	}
};

