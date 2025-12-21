// Текст комментариев
#include <iostream> // Подключение библиотеки ввода/вывода
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>

using namespace std;

#define ARRAY_Y_SIZE 2
#define ARRAY_X_SIZE 6

void func(int num, char turn, int arr[ARRAY_Y_SIZE][ARRAY_X_SIZE])
{
    int tmpArr[ARRAY_Y_SIZE][ARRAY_X_SIZE];

    for (int y = 0; y < ARRAY_Y_SIZE; ++y)
    {
        for (int x = 0; x < ARRAY_X_SIZE; ++x)
        {
            tmpArr[y][x] = arr[y][x];
        }
    }

    if (turn == 'L')
    {
        if (num < 0)
        {
            num = ARRAY_X_SIZE + num;
        }

        while (num > ARRAY_X_SIZE)
        {
            num -= ARRAY_X_SIZE;
        }

        int newMove = { 0 };

        for (int y = 0; y < ARRAY_Y_SIZE; ++y)
        {
            for (int x = 0; x < ARRAY_X_SIZE; ++x)
            {
                if (x + num < ARRAY_X_SIZE)
                {
                    arr[y][x] = tmpArr[y][x + num];
                }
                else
                {
                    newMove = ARRAY_X_SIZE - num;
                    arr[y][x] = tmpArr[y][x - newMove];
                }


            }
        }
    }

    else if (turn == 'R')
    {
        if (num < 0)
        {
            num = ARRAY_X_SIZE + num;
        }

        while (num > ARRAY_X_SIZE)
        {
            num -= ARRAY_X_SIZE;
        }

        int newMove = { 0 };

        for (int y = 0; y < ARRAY_Y_SIZE; ++y)
        {
            for (int x = 0; x < ARRAY_X_SIZE; ++x)
            {
                if (x - num < 0)
                {
                    newMove = ARRAY_X_SIZE - num;
                    arr[y][x] = tmpArr[y][x + newMove];
                }
                else
                {
                    arr[y][x] = tmpArr[y][x - num];
                }

            }
        }
    }

    else if (turn == 'F')
    {
        if (num < 0)
        {
            num = ARRAY_Y_SIZE + num;
        }

        while (num > ARRAY_Y_SIZE)
        {
            num -= ARRAY_Y_SIZE;
        }

        int newMove = { 0 };

        for (int x = 0; x < ARRAY_X_SIZE; ++x)
        {
            for (int y = 0; y < ARRAY_Y_SIZE; ++y)
            {
                if (y - num < 0)
                {
                    newMove = ARRAY_Y_SIZE - num;
                    arr[y][x] = tmpArr[y + newMove][x];
                }
                else
                {
                    arr[y][x] = tmpArr[y - num][x];
                }

            }
        }
    }

    else if (turn == 'B')
    {
        for (int x = 0; x < ARRAY_X_SIZE; ++x)
        {
            if (num < 0)
            {
                num = ARRAY_Y_SIZE + num;
            }

            while (num > ARRAY_Y_SIZE)
            {
                num -= ARRAY_Y_SIZE;
            }

            int newMove = { 0 };

            for (int x = 0; x < ARRAY_X_SIZE; ++x)
            {
                for (int y = 0; y < ARRAY_Y_SIZE; ++y)
                {
                    if (y + num < ARRAY_X_SIZE)
                    {
                        arr[y][x] = tmpArr[y + num][x];
                    }
                    else
                    {
                        newMove = ARRAY_Y_SIZE - num;
                        arr[y][x] = tmpArr[y - newMove][x];
                    }

                }
            }
        }
    }
}

int main()

{
    int arr[ARRAY_Y_SIZE][ARRAY_X_SIZE] =
    {
        {1, 2, 0, 4, 5, 3},
        {4, 5, 3, 9, 0, 1}
    };

    for (int i = 0; i < ARRAY_Y_SIZE; ++i)
    {
        for (int j = 0; j < ARRAY_X_SIZE; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int num = { 0 };
    char turn = { 'E' };
    char choice = { 'N' };

    while (true)
    {
        cout << "Enter num(0 to do nothing): ";
        
        cin >> num;

        if (num == 0)
        {
            break;
        }

        cout << endl;

        cout << "Enter turn(L, R, F, B): ";
        
        cin >> turn;

        func(num, turn, arr);

        cout << endl << "something else?(Y or N) ";
        cin >> choice;

        if (choice == 'N')
        {
            break;
        }
    }

    

    cout << endl << endl << endl;

    for (int i = 0; i < ARRAY_Y_SIZE; ++i)
    {
        for (int j = 0; j < ARRAY_X_SIZE; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}