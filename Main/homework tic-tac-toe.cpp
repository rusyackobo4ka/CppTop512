// Текст комментариев
#include <iostream> // Подключение библиотеки ввода/вывода
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>

using namespace std;

//tic-tac-toe

void ptintField(char x1, char x2, char x3, char x4, char x5, char x6, char x7, char x8, char x9)
{
    cout << x1 << " | " << x2 << " | " << x3;
    cout << endl;
    cout << "----------";
    cout << endl;
    cout << x4 << " | " << x5 << " | " << x6;
    cout << endl;
    cout << "----------";
    cout << endl;
    cout << x7 << " | " << x8 << " | " << x9;
    cout << endl;
    cout << endl;
}

bool checkWin(char x1, char x2, char x3, char x4, char x5, char x6, char x7, char x8, char x9)
{
    // Горизонтали

    if (x1 == x2 && x2 == x3)
    {
        return true;
    }

    if (x4 == x5 && x5 == x6)
    {
        return true;
    }

    if (x7 == x8 && x8 == x9)
    {
        return true;
    }

    // Вертикали

    if (x1 == x4 && x4 == x7)
    {
        return true;
    }

    if (x2 == x5 && x5 == x8)
    {
        return true;
    }

    if (x3 == x6 && x6 == x9)
    {
        return true;
    }

    // Диагонали

    if (x1 == x5 && x5 == x9)
    {
        return true;
    }

    if (x3 == x5 && x5 == x7)
    {
        return true;
    }

    return false;
}


int main()
{
    char x1 = '1', x2 = '2', x3 = '3', x4 = '4', x5 = '5', x6 = '6', x7 = '7', x8 = '8', x9 = '9';
    int choice = { 0 };

    ptintField(x1, x2, x3, x4, x5, x6, x7, x8, x9);

    while (true)
    {
        cout << "Where paste X?: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            x1 = 'X';
            ptintField(x1, x2, x3, x4, x5, x6, x7, x8, x9);
            break;
        case 2:
            x2 = 'X';
            ptintField(x1, x2, x3, x4, x5, x6, x7, x8, x9);
            break;
        case 3:
            x3 = 'X';
            ptintField(x1, x2, x3, x4, x5, x6, x7, x8, x9);
            break;
        case 4:
            x4 = 'X';
            ptintField(x1, x2, x3, x4, x5, x6, x7, x8, x9);
            break;
        case 5:
            x5 = 'X';
            ptintField(x1, x2, x3, x4, x5, x6, x7, x8, x9);
            break;
        case 6:
            x6 = 'X';
            ptintField(x1, x2, x3, x4, x5, x6, x7, x8, x9);
            break;
        case 7:
            x7 = 'X';
            ptintField(x1, x2, x3, x4, x5, x6, x7, x8, x9);
            break;
        case 8:
            x8 = 'X';
            ptintField(x1, x2, x3, x4, x5, x6, x7, x8, x9);
            break;
        case 9:
            x9 = 'X';
            ptintField(x1, x2, x3, x4, x5, x6, x7, x8, x9);
            break;
        }     
        
        if (checkWin(x1, x2, x3, x4, x5, x6, x7, x8, x9))
        {
            cout << "X win!!!";
            break;
        }

        if ((x1 == 'X' || x1 == 'O') && (x2 == 'X' || x2 == 'O') && (x3 == 'X' || x3 == 'O') && (x4 == 'X' || x4 == 'O') && (x5 == 'X' || x5 == 'O') && (x6 == 'X' || x6 == 'O') && (x7 == 'X' || x7 == 'O') && (x8 == 'X' || x8 == 'O') && (x9 == 'X' || x9 == 'O'))
        {
            cout << "Drow!!!";
            break;
        }

        cout << "Where paste O?: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            x1 = 'O';
            ptintField(x1, x2, x3, x4, x5, x6, x7, x8, x9);
            break;
        case 2:
            x2 = 'O';
            ptintField(x1, x2, x3, x4, x5, x6, x7, x8, x9);
            break;
        case 3:
            x3 = 'O';
            ptintField(x1, x2, x3, x4, x5, x6, x7, x8, x9);
            break;
        case 4:
            x4 = 'O';
            ptintField(x1, x2, x3, x4, x5, x6, x7, x8, x9);
            break;
        case 5:
            x5 = 'O';
            ptintField(x1, x2, x3, x4, x5, x6, x7, x8, x9);
            break;
        case 6:
            x6 = 'O';
            ptintField(x1, x2, x3, x4, x5, x6, x7, x8, x9);
            break;
        case 7:
            x7 = 'O';
            ptintField(x1, x2, x3, x4, x5, x6, x7, x8, x9);
            break;
        case 8:
            x8 = 'O';
            ptintField(x1, x2, x3, x4, x5, x6, x7, x8, x9);
            break;
        case 9:
            x9 = 'O';
            ptintField(x1, x2, x3, x4, x5, x6, x7, x8, x9);
            break;
        }

        if (checkWin(x1, x2, x3, x4, x5, x6, x7, x8, x9))
        {
            cout << "O win!!!";
            break;
        }
    }

    return 0;
}