#include "Guide.h"
#include <iostream>

void Guide::show()
{
	std::cout << _name << ' ' << _user << ' ' << _phone << ' ' << _adress << ' ' << _activity;
}
