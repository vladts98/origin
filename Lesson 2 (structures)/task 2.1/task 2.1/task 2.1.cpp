#include <iostream>

void print_month(int month_number) {
	switch (month_number) {
	case 1:
		std::cout << "Январь";
		break;
	case 2:
		std::cout << "Февраль";
		break;
	case 3:
		std::cout << "Март";
		break;
	case 4:
		std::cout << "Апрель";
		break;
	case 5:
		std::cout << "Май";
		break;
	case 6:
		std::cout << "Июнь";
		break;
	case 7:
		std::cout << "Июль";
		break;
	case 8:
		std::cout << "Август";
		break;
	case 9:
		std::cout << "Сентябрь";
		break;
	case 10:
		std::cout << "Октябрь";
		break;
	case 11:
		std::cout << "Ноябрь";
		break;
	case 12:
		std::cout << "Декабрь";
		break;
	}

	std::cout << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int month_number;
	do {
		std::cout << "Введите номер месяца: ";
		std::cin >> month_number;
		if (month_number > 0 && month_number < 13) {
			print_month(month_number);
		}
		else if (month_number == 0) {
			break;
		}
		else {
			std::cout << "Неправильный номер!" << std::endl;
		}
	} while (month_number != 0);
	std::cout << "До свидания";
}