#include "check_unique.h"

bool check_unique(std::vector <Vehicle*> vector_VC, Vehicle vc)
{
	for (int i = 0; i < vector_VC.size(); i++) {
		if (vector_VC[i]->get_name() != vc.get_name()) {
			continue;
		}
		else { 
			std::cout << vector_VC[i]->get_name() << " уже зарегистрирован!" << std::endl;
			return false;}
	}
	return true;
};