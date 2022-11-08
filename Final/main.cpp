#include <iostream>
#include <Windows.h>
#include "Race.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int reapeat = 0;
	do {
		Race Race;
		std::cout << "����� ���������� � �������� ��������!" << std::endl
			<< "1. " << Race.Race_info.race_1 << std::endl
			<< "2. " << Race.Race_info.race_2 << std::endl
			<< "3. " << Race.Race_info.race_3 << std::endl
			<< "�������� ��� �����: ";
		std::cin >> Race.Race_info.type;
		if (!((Race.Race_info.type == 1) || (Race.Race_info.type == 2) || (Race.Race_info.type == 3)))
			return 1;

		std::cout << "������� ����� ��������� (������ ���� ������������): ";
		std::cin >> Race.Race_info.lenth;
		Race.Create_race();

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
					Race.print_all_info();
					std::cout << "�������� ��������� ��� 0 ��� �������� �������� �����������: ";
					std::cin >> action_regist;
					switch (Race.reg(action_regist)){
					case 0: 
						std::cout << Race.get_v_name(action_regist-1) << " ������� ����������������!" << std::endl;
						break;
					case 1:
						std::cout << "������ �� ���" << std::endl;
						break;
					case 2:
						std::cout << Race.get_v_name(action_regist-1) << " ��� ����������������" << std::endl;
						break;
					case 3:
						std::cout << Race.get_v_name(action_regist-1) << " �� ����� ���� ���������������" << std::endl;
						break;
					case 4:
						break;
					};
				} while (action_regist);
			}
			break; //case 1
			case 2:
				if (Race.get_reg_v() > 1) {
					Race.start();
					for (int i = 0; i < Race.get_reg_v(); i++) {
						std::cout << i + 1 << ". " << Race.get_v_name(i) << ". �����: " << Race.get_time(i) << std::endl;
						}
					break;
				}
				//action = 0;
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
		} while ((!(reapeat == 1)) || (!(reapeat == 2)));
	} while (reapeat == 1);
}