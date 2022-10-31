#include "Vehicles.h"

Vehicle::Vehicle()
{
	this->name = "Транспорт";
	this->speed = 0;
	this->status = false; //в игре или нет
	this->type = 0;
}

float Vehicle::get_time(int L)
{
	return L / this->speed;
}

std::string Vehicle::get_name()
{
	return this->name;
}

bool Vehicle::get_status()
{
	return this->status;
}

void Vehicle::change_status(int race_type)
{
	if (race_type == this->type || race_type == 3) {
		this->status = true; // в игре
	}
	else {
		this->status = false;
	}
}

Ground_vehicle::Ground_vehicle()
{
	this->type = 1;  // 1 - наземное
	this->time_between_rest = 0;
	this->i_rest_time = 0;
	this->rest_time = new float[i_rest_time]();
	//this->i_rest_time = sizeof(rest_time) / sizeof(rest_time[0])
	//static const int i_rest_time = 1;
	//float rest_time[] = { 0 };
}

float Ground_vehicle::get_time(int L)
{
	int i_rest = ((L + 1) / speed) / this->time_between_rest;
	float rest_time = 0;
	for (int i = 0; i < i_rest; ++i) {
		int i_rest = this->i_rest_time < i ? this->i_rest_time : i;
		rest_time += this->rest_time[i_rest];
	}
	float time = L / speed + rest_time;
	return time;
}

Ground_vehicle::~Ground_vehicle()
{
	if (rest_time) {
		delete[] rest_time;
	}
}

Camal::Camal()
{
	this->name = "Верблюд";
	this->speed = 10;
	this->time_between_rest = 30;
	this->i_rest_time = 2;
	this->rest_time = new float[i_rest_time];
	rest_time[0] = 5;
	rest_time[1] = 8;
	}

Camal_fast::Camal_fast()
{
	this->name = "Верблюд быстроход";
	this->speed = 40;
	this->time_between_rest = 10;
	this->i_rest_time = 3;
	this->rest_time = new float[i_rest_time];
	rest_time[0] = 5;
	rest_time[1] = 6,5;
	rest_time[2] = 8;
	}

Kent::Kent()
{
	this->name = "Кентавр";
	this->speed = 15;
	this->time_between_rest = 8;
	this->i_rest_time = 1;
	this->rest_time = new float[i_rest_time];
	rest_time[0] = 2;
	}

Boots_fast::Boots_fast()
{
	this->name = "Ботинки быстроходы";
	this->speed = 6;
	this->time_between_rest = 60;
	this->i_rest_time = 2;
	this->rest_time = new float[i_rest_time];
	rest_time[0] = 10;
	rest_time[1] = 5;
}