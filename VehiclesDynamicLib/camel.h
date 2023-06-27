#pragma once
#include <iostream>
#include "ground_vehicle.h"
#include "vehicle.h"

class Camel : public GroundVehicle 
{
public:
	CALCULATESPEEDLIBRARY_API Camel();
	CALCULATESPEEDLIBRARY_API double calculate_time(int distance) override;
protected:
	double _rest_duration_01;
	double _rest_duration_02;
};
