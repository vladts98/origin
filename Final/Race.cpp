#include "Race.h"

Race::Race() {
	this->reg_v = 0;
}

Race::~Race() {
	delete[] this->Vehicles;
	/*if (all_v > 1) {
		delete[] Vehicles;
	}
	else {
		delete Vehicles;
	}*/
}

void Race::Create_race() {
	this->Vehicles = new Vehicle[this->all_v]();
	Vehicles[0] = Camal(this->Race_info.lenth);
	Vehicles[1] = Camal_fast(this->Race_info.lenth);
	Vehicles[2] = Kent(this->Race_info.lenth);
	Vehicles[3] = Boots_fast(this->Race_info.lenth);
	Vehicles[4] = Magic_carpet(this->Race_info.lenth);
	Vehicles[5] = Eagle(this->Race_info.lenth);
	Vehicles[6] = Broom(this->Race_info.lenth);
}

int Race::get_all_v() {
	return this->all_v;
}

int Race::get_reg_v() {
	return this->reg_v;
}

float Race::get_time(const int i) {
	return this->Vehicles[i].get_time();
}

void Race::print_all_info() {
	switch (this->Race_info.type) {
	case 1:
		std::cout << this->Race_info.race_1;
		break;
	case 2:
		std::cout << this->Race_info.race_2;
		break;
	case 3:
		std::cout << this->Race_info.race_3;
		break;
	}
	std::cout << ". –ассто€ние: " << this->Race_info.lenth << std::endl;
	if (this->reg_v> 0) {
		std::cout << "«арегистрированные транспортные средства: ";
		for (int i = 0, reg_v = 0; reg_v < this->reg_v; ++i) {
			if (this->Vehicles[i].get_status() == true) {
				++reg_v;
				std::cout << this->Vehicles[i].get_name();
				if (reg_v < this->reg_v) {
					std::cout << ", ";
				}
				else {
					std::cout << std::endl;
				}
			}
		}
	}
	for (int i = 0; i < this->get_all_v(); ++i) {
		std::cout << i + 1 << " " << this->Vehicles[i].get_name() << std::endl;
	}
}

std::string Race::get_v_name(const int n) {
	return this->Vehicles[n].get_name();
}

int Race::reg(unsigned int n) {
	if (n == 0) {
		return 4;					// конец регистрации
	} else if (n > this->all_v) {
		return 1;					// “— не существует
	}
	else {
		n = n - 1;
		if (this->Vehicles[n].get_status()) {
			return 2;				// уже зарегестрировали
		}
		else {
			this->Vehicles[n].change_status(this->Race_info.type);
			if (this->Vehicles[n].get_status()) {
				this->reg_v++;		// зарегестрировали
				return 0;
			}
			else {
				return 3;			// не может зарегестрироватьс€
			}
		}
	}
}

void Race::start() {
	const int L = this->Race_info.lenth;
	for (int i = 0; i < this->all_v - 2; i++) {
		if (this->Vehicles[i].get_time() < this->Vehicles[i].get_time()) {
			//std::swap(this->Vehicles[i], this->Vehicles[i+1]);
			//i = 0;
		}
	}
}