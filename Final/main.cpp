#include <iostream>
#include <Windows.h>
#include "Race.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int reapeat = 0;
	do {
		Race Race;
		std::cout << "����� ���������� � �������� ��������!" << std::endl;
		for (int i = 0; i < Race.max_type; ++i) {
			std::cout << i + 1 << " " << Race.type_name[i] << std::endl;
		}
		std::cout << "�������� ��� �����: ";
		int type;
		std::cin >> type;

		std::cout << "������� ����� ��������� (������ ���� ������������): ";
		float lenth;
		std::cin >> lenth;
		Race.Create_race(type, lenth);

		int action = 0;
		while (action != 2) {
			if (Race.get_reg_v() < 2) {
				std::cout << "������ ���� ���������������� ���� �� 2 ������������ ��������" << std::endl;
			}
			std::cout << "1. ���������������� ���������" << std::endl;
			if (Race.get_reg_v() > 1) {
				std::cout << "2. ������ �����" << std::endl;
			}
			std::cout << "�������� ��������: ";
			std::cin >> action;

			switch (action) {
			case 1:
			{
				int action_regist = 1;
				do {
					std::cout << std::endl;
					Race.print_all_info();
					std::cout << "�������� ��������� ��� 0 ��� �������� �������� �����������: ";
					std::cin >> action_regist;
					switch (Race.reg(action_regist)) {
					case 0:
						std::cout << Race.get_v_name(action_regist - 1) << " ������� ���������������!" << std::endl;
						break;
					case 1:
						std::cout << "������ �� ���" << std::endl;
						break;
					case 2:
						std::cout << Race.get_v_name(action_regist - 1) << " ��� ���������������" << std::endl;
						break;
					case 3:
						std::cout << Race.get_v_name(action_regist - 1) << " �� ����� ���� ���������������" << std::endl;
						break;
					case 4:
						break;
					};
				} while (action_regist);
			}
			break;
			case 2:
				if (Race.get_reg_v() > 1) {
					Race.start();
					for (int i = Race.get_all_v() - 1, n = 1; i > -1; --i) {
						if (Race.get_v_status(i)) {
							std::cout << n << ". " << Race.get_v_name(i) << ". �����: " << Race.get_time(i) << std::endl;
							++n;
						}
					}
					break;
				}
				break;
			default:
				action = 0;
				break;
			}
		}
		do {
			std::cout << std::endl << "1. �������� ��� ���� �����" << std::endl
				<< "2. �����" << std::endl;
			std::cout << "�������� ��������: ";
			std::cin >> reapeat;
		} while (!((reapeat == 1) || (reapeat == 2)));
	} while (reapeat == 1);
}