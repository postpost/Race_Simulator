#pragma once
#include <iostream>
#include "vehicle.h"

class DistanceError :public std::exception 
{
public:
	CALCULATESPEEDLIBRARY_API const char* what() const override;
};