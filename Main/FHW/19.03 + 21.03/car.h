#pragma once

#include <string>

class car final
{
public:
	car(std::string name, int age, int engCap, int price) : _name(name), _age(age), _engCap(engCap), _price(price) {}
	~car() = default;

	std::string getName() { return _name; }
	int getAge() { return _age; }
	int getEngCap() { return _engCap; }
	int getPrice() { return _price; }

	void printInfo();

private:
	std::string _name;
	int _age;
	int _engCap;
	int _price;
};

