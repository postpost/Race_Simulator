#pragma once
#include "vehicle.h"


class GroundVehicle :public Vehicle {
public:
	CALCULATESPEEDLIBRARY_API GroundVehicle();
	//CALCULATESPEEDLIBRARY_API double calculate_time(int distance) override;
	//CALCULATESPEEDLIBRARY_API void printRaceResults(const int size, int distance) override;

protected:
	int _speed;
	int _rest_distance_time;
};
