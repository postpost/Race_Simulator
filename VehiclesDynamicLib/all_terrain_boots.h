#pragma once
#include "ground_vehicle.h"
#include "vehicle.h"

class AllTerrainBoots : public GroundVehicle
{
public:
	CALCULATESPEEDLIBRARY_API AllTerrainBoots();
	CALCULATESPEEDLIBRARY_API double calculate_time(int distance) override;
protected:
	double _rest_duration_01;
	double _rest_duration_02;
};
