#pragma once
#include "air_vehicle.h"
#include "ground_vehicle.h"
#include "vehicle.h"


class CarpetPlane :public AirVehicle 
{
public:
	CALCULATESPEEDLIBRARY_API CarpetPlane();
	CALCULATESPEEDLIBRARY_API double calculate_time(int distance) override;
};
