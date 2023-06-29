#pragma once
#include "vehicle.h"

class AirVehicle : public Vehicle {
public:
	AirVehicle();

protected:
	int _speed;
	double _distance_reduce_coef;
	//double race_result;
	CALCULATESPEEDLIBRARY_API double calculate_time(int distance) override;
};

