#include "eagle.h"
#include "DistanceError.h"

Eagle::Eagle() 
{
	vehicle_name = "Îð¸ë";
	_speed = 8;
	_distance_reduce_coef = 6;
};

double Eagle::calculate_time(int distance)
{
	if (distance < 0)
	{
		throw DistanceError();
	}
	race_result = (double)distance * _distance_reduce_coef / 100;
	return race_result;
};