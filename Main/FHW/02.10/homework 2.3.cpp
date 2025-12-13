// Текст комментариев
#include <iostream> // Подключение библиотеки ввода/вывода
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>
#include <vector>
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

vector<int> split(int num)
{
    vector<int> digits;

    while (num)
    {
        digits.push_back (num % 10);
        num /= 10;
    }

    return digits;
}

int binTo10(int num)
{
    vector<int> tmp = split(num);
    int result = 0;

    for (int i = 0; i < tmp.size(); ++i)
    {
        result += tmp[i] * step(2, i);
    }

    return result;
}

int main()
{
    cout << binTo10(1011101);

    return 0;
}