#include "Registration.h"

void Registration(Vehicle* V, Race* race)
{
	if (V->get_status()) {
		std::cout << V->get_name() << " уже зарагестрировано" <<std::endl;
	} else {
		V->change_status(race->type);
		if (V->get_status()) {
			std::cout << V->get_name() << " успешно зарегестрировано!" << std::endl;
			race->cars++;
		}
		else {
			std::cout << V->get_name() << " не может быть зарегестрирован" << std::endl;
		}
	}
}
