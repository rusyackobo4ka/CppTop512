// Текст комментариев
#include <iostream> // Подключение библиотеки ввода/вывода
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>

using namespace std;

bool checkLuckyNum(int number) 
{

    if (number < 100000 || number > 999999) 
    {
        return false;
    }

    // Разбиваем число на цифры
    int num1 = number / 100000;           
    int num2 = (number / 10000) % 10;
    int num3 = (number / 1000) % 10;
    int num4 = (number / 100) % 10;
    int num5 = (number / 10) % 10;
    int num6 = number % 10;

    return (num1 + num2 + num3) == (num4 + num5 + num6);
}

int main()
{
    cout << checkLuckyNum(123241);
    return 0;
}