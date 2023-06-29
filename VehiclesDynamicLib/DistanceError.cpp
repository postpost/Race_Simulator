#include "DistanceError.h"

const char* DistanceError::what() const 
{ 
	return "Расстояние ниже нуля!"; 
}