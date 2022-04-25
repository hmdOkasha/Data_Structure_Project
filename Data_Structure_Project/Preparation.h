#pragma once
#include<iostream>
#include "Events.h"
#include "Cargo.h"
#include "Time.h"
using namespace std;
class Preparation :Events
{
public:
	void Execute(Time P_T, Time L_T, cargoType C_T, int dist, int cst, int ID )
	{
		Cargo C;
		C.setPreparationTime(P_T);
		C.setLoadAndUnloadTime(L_T);
		C.setTypeOfCargo(C_T);
		C.setDeliveryDistance(dist);
		C.setCost(cst);
		C.setID(ID);

	}
};