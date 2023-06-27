#include "registrate.h"
#include "check_unique.h"
#include "print_registrated.h"

void registrate(Vehicle*& array, int& size, Vehicle vc)
{
	if (check_unique(array, size, vc) == true) {
		Vehicle* newVcArray = new Vehicle[size + 1];
		if (size == 0) {
			newVcArray[0] = vc;
			size++;
		}
		else {
			for (int i = 0; i < size; i++)
			{
				//newVcArray[i] = this[i];
				newVcArray[i] = array[i];
			}
			newVcArray[size++] = vc;
		}
		delete[] array; //error
		array = newVcArray;
	}
	print_registarted(array, size);

};
