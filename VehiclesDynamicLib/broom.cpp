#include "broom.h"
#include "DistanceError.h"

Broom::Broom()
{
	vehicle_name = "Метла";
	_speed = 20;
};

double Broom:: calculate_time(int distance)
{
	if (distance < 0)
	{
		throw DistanceError();
	}

	for (size_t i = 1000; i <= distance; i+=1000)
	{
		_distance_reduce_coef += 1;
	}

	race_result = (double)distance * _distance_reduce_coef / 100;
	return race_result;
};