#include "all_terrain_boots.h"
#include "DistanceError.h"

AllTerrainBoots::AllTerrainBoots()
{
	vehicle_name = "Ботинки-вездеходы";
	_speed = 6;
	_rest_distance_time = 60;
	_rest_duration_01 = 10;
	_rest_duration_02 = 5;
};

double AllTerrainBoots::calculate_time(int distance)
{
	if (distance < 0)
	{
		throw DistanceError();
		return 1;
	}

	double distance_time = (double)distance / _speed;
	double times_to_rest = distance_time / _rest_distance_time;
	double _length_rest_change = 1;
	double final_time = distance_time + _rest_duration_01;
	int count = 1;
		for (int i = 0; i < (int)times_to_rest - _length_rest_change; i++)
		{
			final_time += _rest_duration_02;
			++count;
			//std::cout << final_time << "--" << times_to_rest - _length_rest_change << "--" << i << std::endl;
		}
		race_result = final_time;
	return final_time;
};


