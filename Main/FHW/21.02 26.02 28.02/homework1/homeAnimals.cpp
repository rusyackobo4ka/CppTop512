#include "homeAnimals.h"

void homeAnimals::displayInfo()
{
	std::cout << "Name: " << _name << std::endl;
	std::cout << "Age: " << _age << " years" << std::endl;
	std::cout << "Color: " << _color << std::endl;
}

void dog::displayInfo()
{
	homeAnimals::displayInfo();
	std::cout << "breed: " << breed << std::endl;
}

void dog::wantPlay()
{
	std::cout << _name << "Want play!" << std::endl;
}

void dog::attack()
{
	std::cout << _name << "Atack!!!" << std::endl;
}

void cat::displayInfo()
{
	homeAnimals::displayInfo();
	std::cout << "fav toy: " << _toy << std::endl;
}

void cat::purr()
{
	std::cout << _name << " mur mur..." << std::endl;
}

void parrot::displayInfo()
{
	homeAnimals::displayInfo();
	std::cout << "specias: " << _species << std::endl;
	std::cout << "Can talk: " << (_canTalk ? "Y" : "N") << std::endl;
}

void parrot::fly()
{
	std::cout << _name << " Flying!" << std::endl;
}
