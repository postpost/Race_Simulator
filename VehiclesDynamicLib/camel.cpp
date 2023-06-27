#include "camel.h"
#include "DistanceError.h"

Camel::Camel()
{
	vehicle_name = "Верблюд";
	_speed = 10;
	_rest_distance_time = 30;
	_rest_duration_01 = 5;
	_rest_duration_02 = 8;
	
};


double Camel::calculate_time(int distance) 
{
	if (distance < 0)
	{
		throw DistanceError();
		return 1;
	}

	double distance_time = (double)distance / _speed;
	double times_to_rest = distance_time / _rest_distance_time;
	double _length_rest_change = 1;
	double final_time = (int)distance_time + _rest_duration_01;
	int count = 1;
		for (int i = 0; i < times_to_rest - _length_rest_change; i++)
		{
			final_time += _rest_duration_02;
			++count;
			//std::cout << final_time << "--" << times_to_rest - _length_rest_change << "--" << i << std::endl;
		}
		race_result = final_time;
	return final_time;
};
