#pragma once
#include "Trucks.h"
class VIPTrucks :  public Trucks
{
private:
	TruckType typeOfTruck;
	int truckCapacity;
	Time maintenanceTime;
	int speed;
	Time deliveryInterval;

public:
	VIPTrucks()
	{
		typeOfTruck = Normal;
		truckCapacity = 0;
		maintenanceTime.setTime(0, 0);
		speed = 0;
		deliveryInterval.setTime(0, 0);
	}
	VIPTrucks(TruckType TT, int TC, Time MT, int Speed, Time DI)
	{
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
		return maintenanceTime.toInt(maintenanceTime);
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
		return deliveryInterval.toInt(deliveryInterval);
	}
};

