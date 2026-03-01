#pragma once

#include <iostream>
#include <string>

class homeAnimals
{
public:
	homeAnimals() : _name("0"), _age(0), _color("0") {}
	homeAnimals(std::string& name, int age, std::string& color) : _name(name), _age (age), _color(color) {}
	homeAnimals(int age, int weight, std::string color) {}
	virtual ~homeAnimals() {}

	virtual void displayInfo();

	std::string getName() const {return _name;}
	int getAge() const {return _age;}
	std::string getColor() const {return _color;}

protected:
	std::string _name;
	int _age;
	std::string _color;
};

class dog : public homeAnimals
{
public:
	dog(std::string& dogName, int dogAge, std::string& dogColor, std::string& dogBreed) : homeAnimals(dogName, dogAge, dogColor), breed(dogBreed) {}	

	void displayInfo() override;
	void wantPlay();
	void attack();
private:
	std::string breed;
};

class cat : public homeAnimals
{
public:
	cat(std::string& catName, int catAge, std::string& catColor, std::string& toy) : homeAnimals(catName, catAge, catColor), _toy(toy) {}

	void displayInfo() override;
	void purr();

private:
	std::string _toy;
};

class parrot : public homeAnimals
{
public:
	parrot(std::string& parrotName, int parrotAge, std::string& parrotColor, std::string& parrotSpecies, bool talk) : homeAnimals(parrotName, parrotAge, parrotColor), species(parrotSpecies), canTalk(talk) {}
		
	void displayInfo() override;
	void fly();

private:
	std::string _species;                 
	bool _canTalk;
};

