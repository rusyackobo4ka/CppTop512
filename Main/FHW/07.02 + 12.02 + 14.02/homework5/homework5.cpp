#include <iostream>
#include "date.h"

int main()
{
    Date birthday(15, 8, 1990);
    std::cout << "birthday: " << birthday << "\n";

    Date copy = birthday;
    std::cout << "copy: " << copy << "\n";

    birthday.setDay(20);
    std::cout << "changed: " << birthday << "\n";

    birthday++;
    std::cout << "b++: " << birthday << "\n";
    ++birthday;
    std::cout << "++b: " << birthday << "\n";

    birthday--;
    std::cout << "b--" << birthday << "\n";
    --birthday;
    std::cout << "--b: " << birthday << "\n";

    birthday += 5;
    std::cout << "+=b: " << birthday << "\n";

    std::cout << "copy < b?: " << (copy < birthday) << "\n";

    std::cout << "copy == b?: " << (copy == birthday) << "\n";
    copy = birthday;
    std::cout << "copy == b?: " << (copy == birthday) << "\n";

    std::string example;

    example = birthday();

    std::cout << "date: " << birthday << ", string: " << example;

    return 1;
}

