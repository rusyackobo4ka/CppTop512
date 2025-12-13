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
    int firstArr[ARRAY_SIZE] = { 3365, 2, 76, 4, 5 };

    int secondArr[ARRAY_SIZE];

    int* firstPtr = firstArr;
    int* secondPtr = secondArr;


    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        *secondPtr = *firstPtr;
        firstPtr++;
        secondPtr++;
    }



    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        cout << firstArr[i] << " ";
    }

    cout << endl << "-=========================-" << endl;

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        cout << secondArr[i] << " ";
    }

    cout << endl;

    return 0;
}