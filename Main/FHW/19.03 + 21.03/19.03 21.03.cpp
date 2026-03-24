#include <iostream>


#include "car.h"
#include "CRUD.h"






int main()
{
    CRUD face;
    face.addCar(car("ad", 2020, 20, 50));
    face.addCar(car("sec", 2040, 550, 570));

    if (!face.deleteCar("ad"))
    {
        return 0;
    }

    face.printCars();

    return 0;
}

