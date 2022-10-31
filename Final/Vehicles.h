#pragma once
#include <iostream>

class Vehicle {
public:
	Vehicle();
	virtual float get_time(int L);
	std::string get_name();
	bool get_status();
	void change_status(int race_type);
protected:
	std::string name;
	int speed;
	bool status; //в игре или нет
	int type; //тип ТС
};

class Ground_vehicle : public Vehicle {
public:
	Ground_vehicle();
	float get_time(int L) override;
	~Ground_vehicle();
protected:
	int time_between_rest;
	int i_rest_time;
	float* rest_time = nullptr;
	//const int i_rest_time; //= sizeof(&rest_time) / sizeof(&rest_time[0]);
};

class Camal : public Ground_vehicle {
public:
	Camal();
};

class Camal_fast : public Ground_vehicle {

public:
	Camal_fast();
};

class Kent : public Ground_vehicle {
public:
	Kent();
};

class Boots_fast : public Ground_vehicle {
public:
	Boots_fast();
};

class Air_vehicle : public Vehicle {
public:
	Air_vehicle();
protected:
	int type = 2;  // 2 - воздушное
};

