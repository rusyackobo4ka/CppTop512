// Текст комментариев
#include <iostream> // Подключение библиотеки ввода/вывода
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>

#include "class.h"



int main() // Это главная функция программы - Ее начало и ее конец
{
    complexNumber num1(3, 4);
    complexNumber num2(1, 2);

    double num = 4;
    drob dNum(2, 5);

    (num1 + num2).printCompNum(); std::cout << "   +|" << "\n";
    (num1 - num2).printCompNum(); std::cout << "   -|" << "\n";
    (num1 * num2).printCompNum(); std::cout << "   *|" << "\n";
    (num1 / num2).printCompNum(); std::cout << "   /|" << "\n";

    std::cout << "-==========================-" << "\n";

    (num1 + num).printCompNum(); std::cout << "   +|" << "\n";
    (num1 - num).printCompNum(); std::cout << "   -|" << "\n";
    (num1 * num).printCompNum(); std::cout << "   *|" << "\n";
    (num1 / num).printCompNum(); std::cout << "   /|" << "\n";

    std::cout << "-==========================-" << "\n";

    (num1 + dNum).printCompNum(); std::cout << "   +|" << "\n";
    (num1 - dNum).printCompNum(); std::cout << "   -|" << "\n";
    (num1 * dNum).printCompNum(); std::cout << "   *|" << "\n";
    (num1 / dNum).printCompNum(); std::cout << "   /|" << "\n";

    std::cout << "-==========================-" << "\n";



    return 0;
}

