#include <iostream>

enum month {
	January = 1,
	February,
	March,
	April,
	May	,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

void print_monthV1(int month_number) {

	switch (month_number) {
	case January: // наводя на January он пишет "month::January = 1" и получается даже без static_cast все работет.
		std::cout << "Январь";
		break;
	case February:
		std::cout << "Февраль";
		break;
	case March:
		std::cout << "Март";
		break;
	case April:
		std::cout << "Апрель";
		break;
	case May:
		std::cout << "Май";
		break;
	case June:
		std::cout << "Июнь";
		break;
	case July:
		std::cout << "Июль";
		break;
	case August:
		std::cout << "Август";
		break;
	case September:
		std::cout << "Сентябрь";
		break;
	case October:
		std::cout << "Октябрь";
		break;
	case November:
		std::cout << "Ноябрь";
		break;
	case December:
		std::cout << "Декабрь";
		break;
	}
	std::cout << std::endl;
}

oid print_monthV2(int month_number) {

	switch (month_number) {
	case January: // наводя на January он пишет "month::January = 1" и получается даже без static_cast все работет.
		std::cout << "Январь";
		break;
	case February:
		std::cout << "Февраль";
		break;
	case March:
		std::cout << "Март";
		break;
	case April:
		std::cout << "Апрель";
		break;
	case May:
		std::cout << "Май";
		break;
	case June:
		std::cout << "Июнь";
		break;
	case July:
		std::cout << "Июль";
		break;
	case August:
		std::cout << "Август";
		break;
	case September:
		std::cout << "Сентябрь";
		break;
	case October:
		std::cout << "Октябрь";
		break;
	case November:
		std::cout << "Ноябрь";
		break;
	case December:
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
			print_monthV2(month_number);
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