#include "car.h"
#include <iostream>

void car::printInfo()
{
	std::cout << "Name: " << _name << "\n" << "Year: " << _age << "\n" << "Engige: " << _engCap << "\n" << "Price: " << _price << "$ " << "\n";
	std::cout << std::string(50, '=') << "\n";
}
