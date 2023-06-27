#include "speed_camel.h"
#include "DistanceError.h"

SpeedCamel::SpeedCamel()
{
	vehicle_name = "Верблюд-быстроход";
	_speed = 40;
	_rest_distance_time = 10;
	_rest_duration_01 = 5;
	_rest_duration_02 = 6.5;
	_rest_duration_03 = 8;
}

double SpeedCamel::calculate_time(int distance)
{
	if (distance < 0)
	{
		throw DistanceError();
		return 1;
	}

	double distance_time = (double)distance / _speed;
	double times_to_rest = distance_time / _rest_distance_time;
	double _length_rest_change = 2;
	double final_time = distance_time + _rest_duration_01 + _rest_duration_02;
	int count = 1;
		for (int i = 0; i < (int)times_to_rest - _length_rest_change; i++)
		{
			final_time += _rest_duration_03;
			++count;
			//std::cout << final_time << "--" << times_to_rest - _length_rest_change << "--" << i << std::endl;
		}
		race_result = final_time;
	return final_time;
};