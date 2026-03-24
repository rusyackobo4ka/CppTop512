#include "CRUD.h"
#include <iostream>

void CRUD::addCar(car someCar)
{
	cars.emplace_back(someCar);
}

bool CRUD::deleteCar(std::string name)
{
	for (int i = 0; i < cars.size(); ++i)
	{
		if (cars[i].getName() == name)
		{
			cars.erase(cars.begin() + i);
			std::cout << "yeap" << "\n";
			return true;
		}
	}
	std::cout << "error" << "\n";
	return false;
}

void CRUD::printCars()
{
	for (int i = 0; i < cars.size(); ++i)
	{
		cars[i].printInfo();
	}
}
