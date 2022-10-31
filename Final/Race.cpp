#include "Race.h"

void Race::info(Vehicle* all_cars) {     //, const int* size) {
	switch (this->type) {
	case 1:
		std::cout << this->race_1;
		break;
	case 2:
		std::cout << this->race_2;
		break;
	case 3:
		std::cout << this->race_3;
		break;
	}
	std::cout << ". Расстояние: " << this->lenth << std::endl;
	if (this->cars > 0) {
		std::cout << "Зарегистрированные транспортные средства: ";
		for (int i = 0, reg_car = 0; reg_car < this->cars; ++i) {
			if (all_cars[i].get_status() == true) {
				++reg_car;
				std::cout << all_cars[i].get_name();
				if (i < this->cars - 1) {
					std::cout << ", ";
				}
				else {
					std::cout << std::endl;
				}
			}
		}
	}
}