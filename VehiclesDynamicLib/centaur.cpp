#include "centaur.h"
#include "DistanceError.h"

Centaur::Centaur()
{
	vehicle_name = "Кентавр";
	_speed = 15;
	_rest_distance_time = 8;
	_rest_duration_01 = 2;
};

double Centaur::calculate_time(int distance)
{
	if (distance < 0)
	{
		throw DistanceError();
		return 1;
	}

	double distance_time = (double)distance / _speed;
	double times_to_rest = distance_time / _rest_distance_time;
	double _length_rest_change =0;
	double final_time = distance_time;
	int count = 1;
		for (int i = 0; i < (int)times_to_rest - _length_rest_change; i++)
		{
			final_time += _rest_duration_01;
			++count;
			
		}
		race_result = final_time;
	return final_time;

};



