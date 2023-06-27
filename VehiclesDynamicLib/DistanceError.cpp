#include "DistanceError.h"

const char* DistanceError::what() const 
{ 
	return "Distance is below zero!"; 
}