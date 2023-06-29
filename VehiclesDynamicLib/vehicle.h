#pragma once
#include <iostream>
#ifndef CALCULATESPEEDLIBRARYDYNAMIC_EXPORTS
#define CALCULATESPEEDLIBRARY_API __declspec(dllexport)
#else
#define CALCULATESPEEDLIBRARY_API __declspec(dllimport)
#endif //CALCULATESPEEDLIBRARYDYNAMIC_EXPORTS

class Vehicle {
protected:
	std::string vehicle_name;
	double race_result;
public:
	CALCULATESPEEDLIBRARY_API Vehicle();
	CALCULATESPEEDLIBRARY_API ~Vehicle();
	CALCULATESPEEDLIBRARY_API virtual double calculate_time(int distance);
	CALCULATESPEEDLIBRARY_API std::string get_name();
	CALCULATESPEEDLIBRARY_API double get_res();
	//CALCULATESPEEDLIBRARY_API void printRaceResults(const int size, int distance);

};
