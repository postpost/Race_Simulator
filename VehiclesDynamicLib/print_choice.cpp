#include "print_choice.h"

void print_choice(int cmd, int distance) 
{
	switch (cmd) {
	case 1:std::cout << "����� ��� ��������� ����������. ����������: " << distance << std::endl;
		break;
	case 2: std::cout << "����� ��� ���������� ����������. ����������: " << distance << std::endl;
		break;
	case 3:std::cout << "����� ��� ��������� � ���������� ����������. ����������: " << distance << std::endl;
		break;
	default: std::cout << "������ �������� ��� �����!";
	}
};