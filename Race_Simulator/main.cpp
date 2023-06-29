#include <iostream>
#include <Windows.h>
#include <vector>
#include "air_vehicle.h"
#include "all_terrain_boots.h"
#include "broom.h"
#include "camel.h"
#include "carpet_plane.h"
#include "centaur.h"
#include "DistanceError.h"
#include "CountError.h"
#include "eagle.h"
#include "ground_vehicle.h"
#include "speed_camel.h"
#include "vehicle.h"
#include "print_registrated.h"
#include "check_unique.h"
#include "print_registrated.h"
#include "print_race_results.h"
#include "print_choice.h"
#include "print_vc_name.h"



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int cmd_continue =0;
	std::cout << "Добро пожаловать в гоночный симулятор!" << '\n';
	do {
			std::cout << "1. Гонка для наземного транспорта" << '\n'
			<< "2. Гонка для воздушного транспорта" << '\n'
			<< "3. Гонка для наземного и воздушного транспорта" << '\n'
			<< "Выберите тип гонки: " << std::endl;
		int race_type_cmd; //select race type
		std::cin >> race_type_cmd;
		int distance;
		std::cout << "Укажите длину дистанции (должна быть положительна): ";
		try {
			std::cin >> distance;
		}
		catch (DistanceError& ex) {
			std::cout << ex.what();
		}

		std::cout << "Должно быть зарегистрировано хотя бы два транспортных средства" << '\n'
			<< "1. Зарегистрировать транспорт" << '\n'
			<< "Выберите действие: ";
		int cmd_registrate; // select registration
		std::cin >> cmd_registrate;

		std::vector <Vehicle*> vehicles;
		int cmd_choice = 0; //select Vehicle 
		int size = 0; //initialize size for Vehicles array
		bool unique = true; //check if VC is unique when registrated
		if (race_type_cmd == 1) {

			print_choice(race_type_cmd, distance);
			do {
				print_vehicle_name();
				std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
				std::cin >> cmd_choice;
				switch (cmd_choice) {
				case 1:
				{AllTerrainBoots terrainBoots;
				check_unique(vehicles, terrainBoots);
				vehicles.push_back(new AllTerrainBoots(terrainBoots));
				//vehicles = &terrainBoots;
				}break;
				case 3:
				{Camel camel;
				check_unique(vehicles, camel);
				vehicles.push_back(new Camel(camel));
				}break;
				case 4:
				{Centaur centaur;
				//GroundVehicle* gr_vc = &centaur;
				check_unique(vehicles, centaur);
				vehicles.push_back(new Centaur(centaur));
				}break;
				case 6:
				{SpeedCamel speedCamel;
				check_unique(vehicles, speedCamel);
				vehicles.push_back(new SpeedCamel(speedCamel));
				}break;
				case 0: if (vehicles.size() < 2) {
					std::cout << "Должно быть зарегистрировано хотя бы два транспортных средства!" << std::endl;
					cmd_choice = 1;
					continue;
					} else { break;};
				default: std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
				}
				
				print_registrated(vehicles);

				if (cmd_choice == 0) {
					std::cout << "\n1. Зарегистрировать транспорт" << '\n'
						<< "2. Начать гонку" << '\n'
						<< "Выберите действие: ";
					int cmd = 0;
					std::cin >> cmd;
					if (cmd != 2) {
						cmd_choice = 1;
						continue;
					}
					else {						
						printRaceResults(vehicles, distance);
						break;
					}
				}
			} while (cmd_choice != 0);
			//vehicles.clear();
		}
		//For AirVehicle
		if (race_type_cmd == 2) {

			std::vector <Vehicle*> vehicles;

			print_choice(race_type_cmd, distance);
			do {
				print_vehicle_name();
				std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
				std::cin >> cmd_choice;
				switch (cmd_choice) {
				case 2:
				{Broom broom;
				check_unique(vehicles, broom);
				vehicles.push_back(new Broom(broom));
				}break;
				case 5:
				{Eagle eagle;
				check_unique(vehicles, eagle);
				vehicles.push_back(new Eagle(eagle));
				}break;
				case 7:
				{CarpetPlane carpet;
				//GroundVehicle* gr_vc = &centaur;
				check_unique(vehicles, carpet);
				vehicles.push_back(new CarpetPlane(carpet));
				}break;
				case 0: if (vehicles.size() < 2) {
					std::cout << "Должно быть зарегистрировано хотя бы два транспортных средства!" << std::endl;
					cmd_choice = 1;
					continue;
				}
					  else { break; };
				default: std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
				}
				print_registrated(vehicles);

				if (cmd_choice == 0) {
					std::cout << "\n1. Зарегистрировать транспорт" << '\n'
						<< "2. Начать гонку" << '\n'
						<< "Выберите действие: ";
					int cmd = 0;
					std::cin >> cmd;
					if (cmd != 2) {
						cmd_choice = 1;
						continue;
					}
					else {
						printRaceResults(vehicles, distance);
						break;
					}
				}
			} while (cmd_choice != 0);
			//vehicles.clear();
		}
		std::cout << "\n1. Провести еще одну гонку" << '\n'
			<< "2. Выйти" << '\n';
			std::cin >> cmd_continue;
	} while (cmd_continue != 2);
	
	return 0;
}