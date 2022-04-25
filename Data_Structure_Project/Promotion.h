#pragma once
#include <iostream>
#include "Events.h"
#include "Cargo.h"
using namespace std;
class Promotion
{
	void Execute(Cargo C)
	{
		if (C.getTypeOfCargo() == Normal && C.is_loaded() == false)
		{
			C.setTypeOfCargo(VIP);
		}
	}
};