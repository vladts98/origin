#pragma once
#include <iostream> 
#include "Vehicles.h"

class Race {
public:
	unsigned int type = 0;
	unsigned int lenth = 0;
	unsigned int cars = 0;
	const std::string race_1 = "����� ��� ��������� ����������";
	const std::string race_2 = "����� ��� ���������� ����������";
	const std::string race_3 = "����� ��� ��������� � ���������� ���������";
	void info(Vehicle* all_cars);  // , const int* size);
};