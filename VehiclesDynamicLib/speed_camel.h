#pragma once
#include "ground_vehicle.h"
#include "vehicle.h"

class SpeedCamel : public GroundVehicle 
{
public:
	CALCULATESPEEDLIBRARY_API SpeedCamel();
	CALCULATESPEEDLIBRARY_API double calculate_time(int distance) override;
protected:
	double _rest_duration_01;
	double _rest_duration_02;
	double _rest_duration_03;
};

