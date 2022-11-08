#pragma once
#include "Vehicles.h"
#include "Race_info.h"

class Race {
public:
	Race();
	~Race();

	Race_info Race_info;
	void Create_race();

	int get_all_v();
	int get_reg_v();
	std::string get_v_name(const int n);
	float get_time(const int i);

	void print_all_info();

	int reg(unsigned int n);
	void start();
private:
	Vehicle *Vehicles = nullptr;
	const int all_v = 7;	//все доступные машины
	int reg_v;				// зарегестрированные машины
};