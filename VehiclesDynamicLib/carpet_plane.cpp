#include "carpet_plane.h"
#include "DistanceError.h"

CarpetPlane::CarpetPlane()
{
	vehicle_name = "����-������";
	_speed = 10;
};

double CarpetPlane::calculate_time(int distance)
{
	if (distance < 0) 
	{
		throw DistanceError();
	}
	if (distance < 1000 && distance > 0) {
		_distance_reduce_coef = 0;
	}
	else if (distance < 5000) 
	{
		_distance_reduce_coef = 3;
	}
	else if (distance < 10000)
	{
		_distance_reduce_coef = 10;
	}

	else if (distance >= 10000)
	{
		_distance_reduce_coef = 5;
	}
	race_result = (static_cast<double>(distance) * ((100 - _distance_reduce_coef) / 100)) / _speed;
	return race_result;
};