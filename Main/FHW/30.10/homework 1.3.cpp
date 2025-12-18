// Текст комментариев
#include <iostream> // Подключение библиотеки ввода/вывода
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>

using namespace std;

#define ARRAY_SIZE 7


void printDay(int num,int inx, int sred)
{

    if (num > sred) 
    {
        switch (inx)
        {
        case 0:
            cout << "Mon bad day" << endl;
            break;
        case 1:
            cout << "Tue bad day" << endl;
            break;
        case 2:
            cout << "Wed bad day" << endl;
            break;
        case 3:
            cout << "Thu bad day" << endl;
            break;
        case 4:
            cout << "Fri bad day" << endl;
            break;
        case 5:
            cout << "Sat bad day" << endl;
            break;
        case 6:
            cout << "Sun bad day" << endl;
            break;
        }
    }
}

int main()
{
    int* week = new int[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        cout << "Enter " << i + 1 << "'th day: ";
        cin >> week[i];
        cout << endl;
    }

    int summ = { 0 };
    int sred = { 0 };

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        summ += week[i];
    }

    sred = summ / ARRAY_SIZE;

    cout << "Sred = " << sred << endl;
    cout << "Summ = " << summ << endl;

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        if (week[i] > sred)
        {
            printDay(week[i],i, sred);
        }
    }

    return 0;
}