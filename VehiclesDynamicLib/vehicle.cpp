#include "vehicle.h"

Vehicle::Vehicle() : vehicle_name{ " " }, race_result{0}
{

};

Vehicle::~Vehicle() = default;


std::string Vehicle::get_name() {
	return vehicle_name;
};

double Vehicle::calculate_time(int distance)
{
	return 0;
};

double Vehicle::get_res() 
{
	return race_result;
};
