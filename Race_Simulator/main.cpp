#include <iostream>
#include <Windows.h>
#include "air_vehicle.h"
#include "all_terrain_boots.h"
#include "broom.h"
#include "camel.h"
#include "carpet_plane.h"
#include "centaur.h"
#include "DistanceError.h"
#include "eagle.h"
#include "ground_vehicle.h"
#include "speed_camel.h"
#include "vehicle.h"
#include "registrate.h"
#include "check_unique.h"
#include "print_registrated.h"
#include "print_race_results.h"


void print_choice(int cmd, int distance)
{
	if (cmd == 1) {
		std::cout << "Гонка для наземного транспорта. Расстояние: " << distance << std:: endl;
	}
	if (cmd == 2) {
		std::cout << "Гонка для воздушного транспорта. Расстояние: " << distance << std::endl;
	}
	if (cmd == 3) {
		std::cout << "Гонка для наземного и воздушного транспорта. Расстояние: " << distance << std::endl;
	}
}

void print_vehicle_name() 
{
	std::cout << "1. Ботинки-вездеходы" << '\n'
		<< "2. Метла" << '\n'
		<< "3. Верблюд" << '\n'
		<< "4. Кентавр" << '\n'
		<< "5. Орёл" << '\n'
		<< "6. Верблюд-быстроход" << '\n'
		<< "7. Ковёр-самолет" << '\n'
		<< "0. Закончить регистрацию" << '\n';
	
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	

	std::cout << "Добро пожаловать в гоночный симулятор!" << '\n'
		<< "1. Гонка для наземного транспорта" << '\n'
		<< "2. Гонка для воздушного транспорта" << '\n'
		<< "3. Гонка для наземного и воздушного транспорта" << '\n'
		<< "Выберите тип гонки: " << std::endl;
	int race_type_cmd; //select race type
	std::cin >> race_type_cmd;
	int distance;
	std::cout << "Укажите длину дистанции (должна быть положительна): ";
	std::cin >> distance;

	std::cout << "Должно быть зарегистрировано хотя бы два транспортных средства" << '\n'
		<< "1. Зарегистрировать транспорт" << '\n'
		<< "Выберите действие: ";
	int cmd_registrate; // select registration
	std::cin >> cmd_registrate;

	int cmd_choice = 0; //select Vehicle 
	int size = 0; //initialize size for Vehicles array
	bool unique = true; //check if VC is unique when registrated
	if (race_type_cmd == 1) {
		
		Vehicle* gr_vehicles = new GroundVehicle[size]; //initialize dynamic array for the vehicles
		
		print_choice(race_type_cmd, distance);
		do {
			print_vehicle_name();
			std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
			std::cin >> cmd_choice;
			switch (cmd_choice) {
			case 1:
			{AllTerrainBoots terrainBoots;
				/*gr_vehicles = &terrainBoots;
				gr_vehicles->calculate_time(distance);*/
				terrainBoots.calculate_time(distance);
				registrate(gr_vehicles,size, terrainBoots);
							
				//save results;
				//print results;
			}; break;
			case 3:
			{Camel camel;
				/*gr_vehicles = &camel;
				gr_vehicles->calculate_time(distance);*/
				camel.calculate_time(distance);
				registrate(gr_vehicles, size, camel);
			}break;
			case 4:
			{Centaur centaur;
				/*gr_vehicles = &centaur;
				gr_vehicles->calculate_time(distance);*/
				centaur.calculate_time(distance);
				registrate(gr_vehicles, size, centaur);
			}break;
			case 6:
			{SpeedCamel speedCamel;
				/*gr_vehicles = &speedCamel;
				gr_vehicles->calculate_time(distance);*/
				speedCamel.calculate_time(distance);
				registrate(gr_vehicles, size, speedCamel);
			}break;
			default: std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
			}
			if (cmd_choice == 0) {
				std::cout << "1. Зарегистрировать транспорт" << '\n'
					<< "2. Начать гонку" << '\n'
					<< "Выберите действие: ";
				int cmd = 0;
				std::cin >> cmd;
				if (cmd != 2) {
					cmd_choice = 1;
					continue;
				}
				else { break; }
			}

		} while (cmd_choice != 0);
		
		printRaceResults(gr_vehicles, size, distance);
		delete[] gr_vehicles;
	}
	
		//1. Registarate min 2 VCs
		// 1. Registrate again (cmd ==0) or 2. startRace(cmd ==2);
		// if 1 --> 
		//
		//registrate_vc (gr_vehicles, size, )

	//}
	//else if (race_type_cmd == 2) {
	//	Vehicle* air_vehicles = new AirVehicle[size];
	//	print_choice(race_type_cmd, distance);
	//	do {
	//		print_vehicle_name();
	//		std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
	//		std::cin >> cmd;
	//		switch (cmd) {
	//			case 2:
	//				{Broom broom;
	//					if (check_unique(air_vehicles, size, broom)) {
	//						registrate_vc(air_vehicles, size, broom);}
	//				}; break;
	//			case 5:
	//				{Eagle eagle;
	//					if (check_unique(air_vehicles, size, eagle)) {
	//					registrate_vc(air_vehicles, size, eagle);}
	//				}; break;
	//			case 7:
	//				{CarpetPlane carpetPlane;
	//				if (check_unique(air_vehicles, size, carpetPlane)) {
	//					registrate_vc(air_vehicles, size, carpetPlane);}
	//			}break;
	//		
	//		default: std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
	//		}
	//		if (cmd == 0) {
	//			std::cout << "1. Зарегистрировать транспорт" << '\n'
	//				<< "2. Начать гонку" << '\n'
	//				<< "Выберите действие: ";
	//			std::cin >> cmd;
	//			if (cmd != 2) {
	//				continue;
	//			}
	//			else { break; }
	//		}
	//	} while (cmd != 0);
	//}
	//else if (race_type_cmd == 3) {
	//	Vehicle* vehicles = new Vehicle[size];

	//}

		//Vehicle* vehicles = new Vehicle[7]{ terrainBoots, broom, camel,centaur, eagle, speedCamel, carpetPlane };
	
}