#include <iostream>
#include <list>


std::list<int> func(int num)
{
    std::list<int> result;
    int a = 0, b = 1;

    while (true) 
    {
        int tmp = a + b;
        if (tmp > num)
        {
            break;
        }

        result.push_back(tmp);
        a = b;
        b = tmp;
    }

    return result;
}

int main()
{
    std::list<int> test = func(15);

    for (auto iter = test.begin(); iter != test.end(); ++iter)
    {
        std::cout << *iter << " ";
    }
    
}
