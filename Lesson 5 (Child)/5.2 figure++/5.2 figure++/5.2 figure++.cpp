#include <iostream>
#include <Windows.h>
#define PI 3.14159265
#include <string>

class Figure {
public:
	Figure() : Figure(0) {
		this->name = "Фигура";
	}
	int get_sides_count() {
		return sides_count;
	}
	std::string get_name() {
		return name;
	}
	float get_side_lenth(int i) {
		return lenth[i];
	}
	float get_angle(int i) {
		return angle[i];
	}
	virtual bool check() {
		return true;
	}
	~Figure() {
		delete[] lenth;
		delete[] angle;
	}
protected:
	Figure(int count) {
		this->sides_count = count;
		if (count != 0) {
			this->lenth = new float[count]();
			this->angle = new float[count]();
		}
		else {
			this->lenth = new float[1]();
			this->angle = new float[1]();
		}
	}
	int sides_count = 0;
	std::string name = "";
	float* lenth = nullptr;
	float* angle = nullptr;
};

class Triangle : public Figure {
public:
	Triangle() : Figure(3) {
		this->name = "Треугольник";
		angle[2] = 50;
		angle[1] = 30;
		angle[0] = 60;
		lenth[0] = 50;
		lenth[1] = 10;
		lenth[2] = 5;
	}
	bool check() override {
		float summ = 0;
		for (int i = 0; i < sides_count; ++i) {
			if (lenth[i] == 0 || angle[i] == 0) {
				return false;
			}
			summ += angle[i];
		}
		if (summ != 180) {
			return false;
		}
		return true;
	}
};

class right_Triangle : public Triangle {
public:
	right_Triangle() : Triangle() {
		this->name = "Прямоугольный треугольник";
		angle[2] = 90;
		angle[1] = 30;
		angle[0] = 180 - angle[2] - angle[1];
		lenth[1] = 50;
		lenth[2] = 10;
		lenth[0] = 5;
	}
};

class isosceles_Triangle : public Triangle {
public:
	isosceles_Triangle() : isosceles_Triangle(10, 40) {  // задается длина основания и угол вершины
		this->name = "Равнобедренный треугольник";
	}
protected:
	isosceles_Triangle(float l, float a = 60) : Triangle() {
		angle[2] = a;
		angle[1] = (180 - angle[2]) / 2;
		angle[0] = angle[1];

		lenth[2] = l;
		lenth[0] = lenth[2] / (2 / cos(angle[1] * PI / 180));
		lenth[1] = lenth[0];
	}
};

class equilateral_Triangle : public isosceles_Triangle {
public:
	equilateral_Triangle() : isosceles_Triangle(10) {  //задается только сторона, угол автоматически 60 градусов
		this->name = "Равносторонний треугольник";
		lenth[1] = lenth[2];
		lenth[0] = lenth[2];
	}
};

class Quadrangle : public Figure {
public:
	Quadrangle() : Figure(4) {
		this->name = "Четырехугольник";

	}
	bool check() override {
		float summ_angle = 0;
		for (int i = 0; i < sides_count; ++i) {
			summ_angle += angle[i];
		}
		if (summ_angle != 360) {
			return false;
		}
		return true;
	}
protected:
	void angle_90() {
		for (int i = 0; i < sides_count; ++i) {
			angle[i] = 90;
		}
	}
	void angle_pair(float angle) {
		if (angle > 90) {
			angle = 180 - angle;
		}
		this->angle[0] = angle;
		this->angle[1] = (360 - 2 * angle) / 2;
		this->angle[2] = this->angle[0];
		this->angle[3] = this->angle[1];
	}

	void lenth_q(float lenth) {
		for (int i = 0; i < sides_count; ++i) {
			this->lenth[i] = lenth;
		}
	}
	void lenth_pair(float ab_lenth, float bc_lenth) {
		lenth[0] = ab_lenth;
		lenth[1] = bc_lenth;
		lenth[2] = lenth[0];
		lenth[3] = lenth[1];
	}
};

class rectangle : public Quadrangle {
public:
	rectangle() : Quadrangle() {
		name = "Прямоугольник";
		angle_90();
		lenth_pair(10, 20);
	}
};

class square : public Quadrangle {
public:
	square() : Quadrangle() {
		name = "Квадрат";
		angle_90();
		lenth_q(10);
	}
};

class parallelogram : public Quadrangle {
public:
	parallelogram() : Quadrangle() {
		name = "Параллелограмм";
		angle_pair(50);
		lenth_pair(10, 20);
	}
};

class rhomb :public Quadrangle {
public:
	rhomb() : Quadrangle() {
		name = "Ромб";
		angle_pair(50);
		lenth_q(10);
	}
};

void print_info(Figure* figure) {
	std::cout << figure->get_name() << ":" << std::endl;
	std::cout << "Количество сторон: " << figure->get_sides_count() << std::endl;

	if (figure->get_name() == "Фигура") {
		std::cout << std::endl;
	}
	else {
		if (figure->check()) {
			std::cout << "Правильный" << std::endl;
		}
		else {
			std::cout << "Неправильный" << std::endl;
		}
		std::cout << "Стороны: ";
		for (int i = 0; i < figure->get_sides_count(); ++i) {
			std::cout << static_cast<char>('A' + i) << " = ";
			std::cout << figure->get_side_lenth(i);
			if (i < figure->get_sides_count() - 1) {
				std::cout << " ";
			}
			else {
				std::cout << std::endl;
			}
		}
		std::cout << "Углы: ";
		for (int i = 0; i < figure->get_sides_count(); ++i) {
			std::cout << static_cast<char>('a' + i) << " = ";
			std::cout << figure->get_angle(i);
			if (i < figure->get_sides_count() - 1) {
				std::cout << " ";
			}
			else {
				std::cout << std::endl;
			}
		}
		std::cout << std::endl;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Figure f;
	print_info(&f);

	Triangle t;
	print_info(&t);

	right_Triangle rt;
	print_info(&rt);

	isosceles_Triangle it;
	print_info(&it);

	equilateral_Triangle et;
	print_info(&et);

	Quadrangle q;
	print_info(&q);

	rectangle r;
	print_info(&r);

	square s;
	print_info(&s);

	parallelogram p;
	print_info(&p);

	rhomb rh;
	print_info(&rh);
}