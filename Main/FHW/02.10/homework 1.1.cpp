// Текст комментариев
#include <iostream> // Подключение библиотеки ввода/вывода
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>

using namespace std;

int step(int num, int stepen)
{
    if (num == 0)
        return 0;

    if (stepen == 0)
        return 1;

    int result = { 1 };

    for (int i = 0; i < stepen; ++i)
    {
        result *= num;
    }

    return result;
}

int main()
{
    cout << step(2, 2);

    return 0;
}