#pragma once
#include "air_vehicle.h"
#include "vehicle.h"

class Broom :public AirVehicle 
{
public:
	CALCULATESPEEDLIBRARY_API Broom();
	CALCULATESPEEDLIBRARY_API double calculate_time(int distance) override;
};
