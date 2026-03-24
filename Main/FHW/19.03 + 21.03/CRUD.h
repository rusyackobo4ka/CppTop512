#pragma once

#include "car.h"
#include <vector>

class CRUD
{
public:
	CRUD() {}
	~CRUD() {}

	void addCar(car someCar);
	bool deleteCar(std::string name);
	void printCars();

private:
	std::vector<car> cars;
};

