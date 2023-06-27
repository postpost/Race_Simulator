#include "check_unique.h"

bool check_unique(Vehicle* array, const int size, Vehicle vc)
{
	for (int i = 0; i < size; i++) {
		if (array[i].get_name() != vc.get_name()) {
			continue;
		}
		else { 
			std::cout << array[i].get_name() << " уже зарегистрирован!" << std::endl;
			return false;}
	}
	return true;
};