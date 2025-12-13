// Текст комментариев
#include <iostream> // Подключение библиотеки ввода/вывода
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>

using namespace std;

int binFind(int arr[], int size, int key)
{
    int left = 0;
    int right = size - 1;

    while (left <= right) 
    {
        int middle = left + (right - left) / 2;

        if (arr[middle] == key) 
        {
            return middle;  
        }

        if (arr[middle] < key) 
        {
            left = middle + 1;  
        }

        else 
        {
            right = middle - 1; 
        }
    }
}

int main()
{
    int array[5] = { 2, 5, 6, 23, 346 };

    cout << binFind(array, 5, 23);

    return 0;
}