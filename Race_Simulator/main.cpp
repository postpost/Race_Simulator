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
	std::cout << "ƒобро пожаловать в гоночный симул€тор!" << '\n';
	do {
			std::cout << "1. √онка дл€ наземного транспорта" << '\n'
			<< "2. √онка дл€ воздушного транспорта" << '\n'
			<< "3. √онка дл€ наземного и воздушного транспорта" << '\n'
			<< "¬ыберите тип гонки: " << std::endl;
		int race_type_cmd; //select race type
		std::cin >> race_type_cmd;
		int distance;
		std::cout << "”кажите длину дистанции (должна быть положительна): ";
		try {
			std::cin >> distance;
		}
		catch (DistanceError& ex) {
			std::cout << ex.what();
		}

		std::cout << "ƒолжно быть зарегистрировано хот€ бы два транспортных средства" << '\n'
			<< "1. «арегистрировать транспорт" << '\n'
			<< "¬ыберите действие: ";
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
				std::cout << "¬ыберите транспорт или 0 дл€ окончани€ процесса регистрации: ";
				std::cin >> cmd_choice;
				switch (cmd_choice) {
				case 1:
				{AllTerrainBoots terrainBoots;
				/*GroundVehicle* terrain = &terrainBoots;*/
				if (check_unique(vehicles, &terrainBoots))
				{
					vehicles.push_back(new GroundVehicle(terrainBoots)); //доступ в данном случае к vehicles[0] невозможен, даже по ссылке
				}
				
				vehicles[0] = &terrainBoots; //дл€ проверки переопределенного метода
				vehicles[0]->calculate_time(distance); //только в этом случае вызываетс€ метод потомка, без этого вызываетс€ метод останавливаетс€ на GroundVehicle
				//vehicles = &terrainBoots;
				}break;
				case 3:
				{Camel camel;
				check_unique (vehicles, &camel);
				vehicles.push_back(new GroundVehicle(camel));
				}break;
				case 4:
				{Centaur centaur;
				//GroundVehicle* gr_vc = &centaur;
				check_unique(vehicles, &centaur);
				vehicles.push_back(new GroundVehicle(centaur));
				}break;
				case 6:
				{SpeedCamel speedCamel;
				if (check_unique(vehicles, &speedCamel)) {
					vehicles.push_back(new GroundVehicle(speedCamel));
				};
				
				}break;
				case 0: if (vehicles.size() < 2) {
					std::cout << "ƒолжно быть зарегистрировано хот€ бы два транспортных средства!" << std::endl;
					cmd_choice = 1;
					continue;
					} else { break;};
				default: std::cout << "ѕопытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
				}
				
				print_registrated(vehicles);

				if (cmd_choice == 0) {
					std::cout << "\n1. «арегистрировать транспорт" << '\n'
						<< "2. Ќачать гонку" << '\n'
						<< "¬ыберите действие: ";
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
				std::cout << "¬ыберите транспорт или 0 дл€ окончани€ процесса регистрации: ";
				std::cin >> cmd_choice;
				switch (cmd_choice) {
				case 2:
				{Broom broom;
				check_unique(vehicles, &broom);
				vehicles.push_back(new AirVehicle(broom));
				}break;
				case 5:
				{Eagle eagle;
				check_unique(vehicles,&eagle);
				vehicles.push_back(new AirVehicle(eagle));
				}break;
				case 7:
				{CarpetPlane carpet;
				//GroundVehicle* gr_vc = &centaur;
				check_unique(vehicles,&carpet);
				vehicles.push_back(new AirVehicle(carpet));
				}break;
				case 0: if (vehicles.size() < 2) {
					std::cout << "ƒолжно быть зарегистрировано хот€ бы два транспортных средства!" << std::endl;
					cmd_choice = 1;
					continue;
				}
					  else { break; };
				default: std::cout << "ѕопытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
				}
				print_registrated(vehicles);

				if (cmd_choice == 0) {
					std::cout << "\n1. «арегистрировать транспорт" << '\n'
						<< "2. Ќачать гонку" << '\n'
						<< "¬ыберите действие: ";
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
		std::cout << "\n1. ѕровести еще одну гонку" << '\n'
			<< "2. ¬ыйти" << '\n';
			std::cin >> cmd_continue;
	} while (cmd_continue != 2);
	
	return 0;
}