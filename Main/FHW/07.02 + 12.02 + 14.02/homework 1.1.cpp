// Текст комментариев
#include <iostream> // Подключение библиотеки ввода/вывода
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>

using namespace std;


//07.02 + 12.02 + 14.02

class drob
{
public:
    drob() : _up(0), _down(1) {}

    drob(int up, int down) : _up(up), _down(down) {}

    ~drob() {}

    void setDrob(const int& up, const int& down)
    {
        _up = up;
        _down = down;
    }

    int getDrobUp()
    {
        return _up;
    }

    int getDrobDown()
    {
        return _down;
    }

    drob& operator+ (const drob& num)
    {
        int finalDown = _down * num._down;
        int finalUp = (_up * num._down) + (num._up * _down);

        drob result;
        result.setDrob(finalUp, finalDown);

        return result;
    }

    drob& operator- (const drob& num)
    {
        int finalDown = _down * num._down;
        int finalUp = (_up * num._down) - (num._up * _down);

        drob result;
        result.setDrob(finalUp, finalDown);

        return result;
    }

    drob& operator* (const drob& num)
    {
        int finalUp = _up * num._up;
        int finalDown = _down * num._down;

        drob result;
        result.setDrob(finalUp, finalDown);

        return result;
    }

    drob& operator/ (const drob& num)
    {
        int finalUp = _up * num._down;
        int finalDown = _down * num._up;

        drob result;
        result.setDrob(finalUp, finalDown);

        return result;
    }

    static drob plus(const drob& first, const drob& second)
    {
        int finalDown = first._down * second._down;
        int finalUp = (first._up * second._down) + (second._up * first._down);

        drob result;
        result.setDrob(finalUp, finalDown);

        return result;
    }

    static drob minus(const drob& first, const drob& second)
    {
        int finalDown = first._down * second._down;
        int finalUp = (first._up * second._down) - (second._up * first._down);

        drob result;
        result.setDrob(finalUp, finalDown);

        return result;
    }

    static drob multi(const drob& first, const drob& second)
    {
        int finalUp = first._up * second._up;
        int finalDown = first._down * second._down;

        drob result;
        result.setDrob(finalUp, finalDown);

        return result;
    }

    static drob division(const drob& first, const drob& second)
    {
        int finalUp = first._up * second._down;
        int finalDown = first._down * second._up;

        drob result;
        result.setDrob(finalUp, finalDown);

        return result;
    }

private:
    int _up;
    int _down;
};

int main() // Это главная функция программы - Ее начало и ее конец
{
    drob one, two;

    one.setDrob(2, 5);
    two.setDrob(5, 2);

    drob res = drob::minus(one, two);

    cout << (one + two).getDrobUp() << "||" << (one + two).getDrobDown();

    return 0;
}
