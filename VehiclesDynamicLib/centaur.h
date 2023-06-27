#pragma once
#include "ground_vehicle.h"
#include "vehicle.h"

class Centaur :public GroundVehicle 
{
public:
	CALCULATESPEEDLIBRARY_API Centaur();
	CALCULATESPEEDLIBRARY_API double calculate_time(int distance) override;
protected:
	double _rest_duration_01;
};
