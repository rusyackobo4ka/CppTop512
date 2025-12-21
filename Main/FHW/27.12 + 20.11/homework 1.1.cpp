// Текст комментариев
#include <iostream> // Подключение библиотеки ввода/вывода
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>

using namespace std;

#define ARRAY_SIZE 4

int main()
{
    int arr[ARRAY_SIZE][ARRAY_SIZE] = {
                                       {48,65,78,45},
                                       {54,44,57,67},
                                       {32,45,87,37},
                                        {22,54,77,88}
    };


    int num = { 0 };

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        for (int j = 0; j < ARRAY_SIZE; ++j)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }

    cout << "Enter num: ";
    cin >> num;
    cout << endl;

    int newArr[ARRAY_SIZE][ARRAY_SIZE + 1];

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        for (int j = 0; j < ARRAY_SIZE; ++j)
        {
            newArr[i][j] = arr[i][j];
        }
    }


    

    for (int i = num + 1; i < ARRAY_SIZE; ++i)
    {
        for (int j = 0; j < ARRAY_SIZE; ++j)
        {
            newArr[j][i + 1] = arr[j][i];
        }
        
    }

    for (int j = 0; j < ARRAY_SIZE; ++j)
    {
        newArr[j][num + 1] = 0;
    }

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        for (int j = 0; j < ARRAY_SIZE + 1; ++j)
        {
            cout << newArr[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}