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
    int arr[ARRAY_SIZE][ARRAY_SIZE];
    int num = { 0 };

    cout << "Enter num: ";
    cin >> num;
    cout << endl;

    arr[0][0] = num;
    int x = { 0 };

    while (x < ARRAY_SIZE)
    {
        for (int y = 1; y < ARRAY_SIZE; ++y)
        {
                arr[x][y] = arr[x][y - 1] + 1;
        }
        if (x == ARRAY_SIZE - 1)
        {
            break;
        }
        arr[x + 1][0] = arr[x][ARRAY_SIZE - 1] + 1;
        ++x;
    }

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        for (int j = 0; j < ARRAY_SIZE; ++j)
        {
            cout << arr[i][j] << " ";
        }
    }

    return 0;
}