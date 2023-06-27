#pragma once
#include "air_vehicle.h"
#include "vehicle.h"

class Eagle :public AirVehicle 
{
public:
	CALCULATESPEEDLIBRARY_API Eagle();
	CALCULATESPEEDLIBRARY_API double calculate_time(int distance) override;
};