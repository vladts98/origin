#include <iostream>
#include <Windows.h>
#include "CreateVeachels.h"
#include "Registration.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int reapeat = 0;
	do {
		Race race;
		std::cout << "����� ���������� � �������� ��������!" << std::endl
			<< "1. " << race.race_1 << std::endl
			<< "2. " << race.race_2 << std::endl
			<< "3. " << race.race_3 << std::endl
			<< "�������� ��� �����: ";
		std::cin >> race.type;
		if (!((race.type == 1) || (race.type == 2) || (race.type == 3)))
			return 1;

		std::cout << "������� ����� ��������� (������ ���� ������������): ";
		std::cin >> race.lenth;

		All_vehicles All_vehicles = nullptr;
		CreateVeachels(all_cars);
		const int size = sizeof(all_cars) / sizeof(all_cars[0]);

		int action = 0;
		while (action != 2) {
			if (race.cars < 2) {
				std::cout << "������ ���� ���������������� ���� �� 2 ������������ ��������" << std::endl;
			}
			std::cout << "1. ���������������� ���������" << std::endl;
			if (race.cars > 1) {
				std::cout << "2. ������ �����" << std::endl;
			}
			std::cout << "�������� ��������: ";
			std::cin >> action;

			switch (action) {
			case 1:
			{
				int action_regist = 1;
				do {
					//std::cout << std::endl;
					race.info(all_cars);
					for (int i = 0; i < size; ++i) {
						std::cout << i + 1 << " " << all_cars[i].get_name() << std::endl;
					}
					std::cout << "�������� ��������� ��� 0 ��� �������� �������� �����������: ";
					std::cin >> action_regist;
					if (action_regist > size) {
						std::cout << "���������� ��" << std::endl;
						action_regist = 0;
					}
					else {
						Registration(&all_cars[action_regist - 1], &race);
					}
				} while (action_regist);
			}
			break; //case 1
			case 2:
				if (race.cars > 1) {
					std::cout << "star_race();" << std::endl;
					//print_result();
					break;
				}
				action = 0;
				break;
			default:
				action = 0;
				break;
			}
		}
		while ((reapeat == 1) || (reapeat == 2)) {
			std::cout << std::endl << "1. �������� ��� ���� �����" << std::endl
				<< "2. �����" << std::endl;
			std::cout << "�������� ��������: ";
			std::cin >> reapeat;
		}
	} while (reapeat == 1);
}