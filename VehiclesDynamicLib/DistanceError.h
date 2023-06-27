#pragma once
#include <iostream>
#include "vehicle.h"

class DistanceError :public std::exception 
{
	CALCULATESPEEDLIBRARY_API const char* what() const override;
};