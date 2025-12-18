// Текст комментариев
#include <iostream> // Подключение библиотеки ввода/вывода
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>

using namespace std;

#define ARRAY_SIZE 10

void func(int* arr1, int* arr2, int* arr3)
{
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        arr3[i] = arr1[i] + arr2[i]; 
    }
}

int main()
{



    return 0;
}