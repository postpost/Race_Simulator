#include "print_registrated.h"

void print_registrated(std::vector <Vehicle*> &VC)
{
	std::cout << "«арегистрированные транспортные средства: " << VC[0]->get_name();
	for (int i = 1; i < VC.size(); i++) {
		std::cout <<  ", " << VC[i]->get_name();
	}
	std::cout << std::endl;
};
