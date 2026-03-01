#include "RootsOfTheEquation.h"


void Equation::printRoots()
{
    std::cout << "Equation: ";
    printEquation();

    std::vector<double> roots = findRoots();

    if (roots.empty())
    {
        std::cout << " no roots" << std::endl;
    }
    else if (roots.size() == 1)
    {
        std::cout << " x = " << roots[0] << std::endl;
    }
    else
    {
        std::cout << " x1 = " << roots[0] << ", x2 = " << roots[1] << std::endl;
    }
}