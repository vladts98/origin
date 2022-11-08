#include "Vehicles.h"

Vehicle::Vehicle()
{
	this->name = "Транспорт";
	this->speed = 0;
	this->status = false; //в игре или нет
	this->type = 0;
	this->time = 0;
}

float Vehicle::get_time()
{
	return this->time;
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
	this->type = 1;					// 1 - наземное
}

Camal::Camal(const float L)
{
	this->name = "Верблюд";
	this->speed = 10;
	this->time = this->calc_time(L);
}

float Camal::calc_time(const float L) {
	int time_between_rest = 30;
	const int i_rest_time = 2;
	float rest_time[i_rest_time] = { 5,8 };

	int i_rest = ((L-1) / this->speed) / time_between_rest;
	float full_rest = 0;
	for (int i = 0; i < i_rest; ++i) {
		int count_rest = i_rest_time > i ? i : (i_rest_time - 1);
		full_rest += rest_time[count_rest];
	}
	float time = L / this->speed + full_rest;
	return time;
}

Camal_fast::Camal_fast(const float L)
{
	this->name = "Верблюд быстроход";
	this->speed = 40;
	this->time = this->calc_time(L);
}

float Camal_fast::calc_time(const float L) {
	float time_between_rest = 10;
	const int i_rest_time = 3;
	float rest_time[i_rest_time] = { 5,6.5,8 };

	int i_rest = ((L-1) / this->speed) / time_between_rest;
	float full_rest = 0;
	for (int i = 0; i < i_rest; ++i) {
		int count_rest = i_rest_time > i ? i : (i_rest_time - 1);
		full_rest += rest_time[count_rest];
	}
	float time = L / this->speed + full_rest;
	return time;
}

Kent::Kent(const float L)
{
	this->name = "Кентавр";
	this->speed = 15;
	this->time = calc_time(L);
}

float Kent::calc_time(const float L) {
	float time_between_rest = 8;
	const int i_rest_time = 1;
	float rest_time[i_rest_time] = { 2 };

	int i_rest = ((L - 1) / this->speed) / time_between_rest;
	float full_rest = 0;
	for (int i = 0; i < i_rest; ++i) {
		int count_rest = i_rest_time > i ? i : (i_rest_time - 1);
		full_rest += rest_time[count_rest];
	}
	float time = L / this->speed + full_rest;
	return time;
}

Boots_fast::Boots_fast(const float L)
{
	this->name = "Ботинки быстроходы";
	this->speed = 6;
	this->time = calc_time(L);
}

float Boots_fast::calc_time(const float L) {
	float time_between_rest = 60;
	const int i_rest_time = 2;
	float rest_time[i_rest_time] = { 10, 5 };

	int i_rest = ((L - 1) / this->speed) / time_between_rest;
	float full_rest = 0;
	for (int i = 0; i < i_rest; ++i) {
		int count_rest = i_rest_time > i ? i : (i_rest_time - 1);
		full_rest += rest_time[count_rest];
	}
	float time = L / this->speed + full_rest;
	return time;
}

Air_vehicle::Air_vehicle() {
	this->type = 2;  // 2 - воздушное
}

Magic_carpet::Magic_carpet(const float L) {
	this->name = "Ковёр-самолёт";
	this->speed = 10;
	this->time = calc_time(L);
}

float Magic_carpet::calc_time(const float L)
{
	if (L < 1000) {
		return (L / this->speed);
	}
	else if (L < 5000) {
		return  (L * (1 - (3. / 100)) / this->speed);
	}
	else if (L < 10000) {
		return (L * (1 - 10. / 100) / this->speed);
	}
	else {
		return (L * (1 - 5. / 100) / this->speed);
	}
}

Eagle::Eagle(const float L) {
	this->name = "Орёл";
	this->speed = 8;
	this->time = calc_time(L);
}

float Eagle::calc_time(const float L)
{
	return (L * (1 - 6. / 100) / this->speed);
}

Broom::Broom(const float L) {
	this->name = "Метла";
	this->speed = 20;
	this->time = calc_time(L);
}

float Broom::calc_time(const float L)
{
	int k = L / 1000;
	return (L * (1 - static_cast<float>(k) / 100) / this->speed);
}