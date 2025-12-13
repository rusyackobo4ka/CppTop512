// Текст комментариев
#include <iostream> // Подключение библиотеки ввода/вывода
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>

using namespace std;

int sumAtoB(int start, int end)
{
    if (start == end - 1 || start == end)
        return 0;

    if (start > end)
        return 404;

    int result = { 0 };

    for (int i = start + 1; i < end; ++i)
    {
        result += i;
    }

    return result;
}

int main()
{
    cout << sumAtoB(6, 11);

    return 0;
}