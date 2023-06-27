#include "print_registrated.h"
#include <iostream>

void print_registarted(Vehicle* array, int size)
{
	std::cout << "«арегистрированные транспортные средства: " << array[0].get_name();
	for (int i = 1; i < size; i++) {
		std::cout << ", " << array[i].get_name();
	}
	std::cout << std::endl;
};
