#include "eagle.h"
#include "DistanceError.h"

Eagle::Eagle()
{
	vehicle_name = "���";
	_speed = 8;
	_distance_reduce_coef = 6;
};

double Eagle::calculate_time(int distance)
{
	if (distance < 0)
	{
		throw DistanceError();
	}
	race_result = (static_cast<double>(distance) * ((100 -_distance_reduce_coef) / 100))/_speed;
	return race_result;
};