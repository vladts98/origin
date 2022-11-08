#pragma once
#include <iostream>

class Vehicle {
public:
	Vehicle();
	float get_time();
	std::string get_name();
	bool get_status();
	void change_status(int race_type);
protected:
	float time;
	std::string name;
	int speed;
	bool status;	//в игре или нет
	int type;		//тип ТС назменый воздушный и тд
};

class Ground_vehicle : public Vehicle {
public:
	Ground_vehicle();
};

class Camal : public Ground_vehicle {
public:
	Camal(const float L);
private:
	float calc_time(const float L) ;
};

class Camal_fast : public Ground_vehicle {
public:
	Camal_fast(const float L);
private:
	float calc_time(const float L) ;

};

class Kent : public Ground_vehicle {
public:
	Kent(const float L);
private:
	float calc_time(const float L) ;
};

class Boots_fast : public Ground_vehicle {
public:
	Boots_fast(const float L);
private:
	float calc_time(const float L) ;
};

class Air_vehicle : public Vehicle {
public:
	Air_vehicle();
};

class Magic_carpet : public Air_vehicle {
public:
	Magic_carpet(const float L);
private:
	float calc_time(const float L) ;
};

class Eagle : public Air_vehicle {
public:
	Eagle(const float L);
private:
	float calc_time(const float L) ;
};

class Broom : public Air_vehicle {
public:
	Broom(const float L);
private:
	float calc_time(const float L) ;
};
