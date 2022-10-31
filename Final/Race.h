#pragma once
#include <iostream> 
#include "Vehicles.h"

class Race {
public:
	unsigned int type = 0;
	unsigned int lenth = 0;
	unsigned int cars = 0;
	const std::string race_1 = "Гонка для наземного транспорта";
	const std::string race_2 = "Гонка для воздушного транспорта";
	const std::string race_3 = "Гонка для наземного и воздушного траспорта";
	void info(Vehicle* all_cars);  // , const int* size);
};