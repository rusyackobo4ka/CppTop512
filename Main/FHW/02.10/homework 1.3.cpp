// Текст комментариев
#include <iostream> // Подключение библиотеки ввода/вывода
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>

using namespace std;

void FindinAtoB(int start, int end)
{
    if (start > end)
        return;

    if (start == end || start == end - 1)
        return;

    int summdel = 1;

    for (int i = start + 1; i < end; ++i)
    {
        int j = 2;
        while (j < i)
        {
            if (i % j == 0)
            {
                summdel += j;
            }

            ++j;
        }

        if (summdel == i)
        {
            cout << i << " cool";
            cout << endl;
        }
        summdel = 1;
    }
}

int main()
{
    FindinAtoB(5, 100);
    return 0;
}