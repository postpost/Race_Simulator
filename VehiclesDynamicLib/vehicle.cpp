#include "vehicle.h"

double Vehicle::calculate_time(int distance)
{
	return 0;
};

Vehicle::Vehicle() 
{

};

std::string Vehicle::get_name() {
	return vehicle_name;
};

void Vehicle::printRaceResults(const int size, int distance)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (this[j].race_result > this[j + 1].race_result) {
				std::swap(this[i], this[j + 1]);
			}
		}
	}
	std::cout << "Результаты гонки:" << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << this[i].get_name()
			<< ". Время: "
			<< this[i].race_result << std::endl;
	}
};
