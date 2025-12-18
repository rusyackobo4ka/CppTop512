// Текст комментариев
#include <iostream> // Подключение библиотеки ввода/вывода
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>

using namespace std;

#define ARRAY_SIZE_1 10
#define ARRAY_SIZE_2 5

void func(int* arr1, int* arr2, int* arr3)
{
    for (int i = 0; i < ARRAY_SIZE_1; ++i)
    {
        if (i < 5)
        {
            arr2[i] = arr1[i];
        }
        else
        {
            arr3[i - ARRAY_SIZE_2] = arr1[i];
        }
    }
}

int main()
{



    return 0;
}