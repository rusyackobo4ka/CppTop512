// Текст комментариев
#include <iostream> // Подключение библиотеки ввода/вывода
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>

using namespace std;

#define ARRAY_SIZE 5

int main()
{
    int Arr[ARRAY_SIZE] = { 3365, 2, 76, 4, 5 };

    int* startPtr = Arr;

    int* endPtr = Arr + ARRAY_SIZE - 1;

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        cout << Arr[i] << " ";
    }

    while (startPtr < endPtr)
    {
        int temp = *startPtr;
        *startPtr = *endPtr;
        *endPtr = temp;

        startPtr++;
        endPtr--;
    }

    cout << endl << "-=========================-" << endl;

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        cout << Arr[i] << " ";
    }

    cout << endl;

    return 0;
}