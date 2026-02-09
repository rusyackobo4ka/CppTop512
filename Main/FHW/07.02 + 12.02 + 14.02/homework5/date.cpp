#include "Date.h"
#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

bool Date::isLeapYear(int year) const 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int Date::daysInMonth(int month, int year) const
{
    static const int days[] = { 31, 28, 31, 30, 31, 30,
                               31, 31, 30, 31, 30, 31 };

    if (month == 2 && isLeapYear(year))
    {
        return 29;
    }
    if (month >= 1 && month <= 12) 
    {
        return days[month - 1];
    }
    return 0;
}
void Date::normalize() 
{
    while (_day > daysInMonth(_month, _year)) 
    {
        _day -= daysInMonth(_month, _year);
        _month++;

        if (_month > 12) 
        {
            _month = 1;
            _year++;
        }
    }

    while (_day <= 0) 
    {
        _month--;
        if (_month < 1) 
        {
            _month = 12;
            _year--;
        }
        _day += daysInMonth(_month, _year);
    }
}



Date::Date() {}
Date::Date(int day, int month, int year) : _day(day), _month(month), _year(year) {}
Date::Date(const Date& date) : _day(date._day), _month(date._month), _year(date._year) {}



void Date::setDay(int day) 
{
    _day = day;
}
void Date::setMonth(int month)
{
    _month = month;
}
void Date::setYear(int year)
{
    _year = year;
}

void Date::setDate(int day, int month, int year)
{
    _day = day;
    _month = month;
    _year = year;
}

void Date::increaseDay() 
{
    _day++;
    normalize();
}

Date& Date::operator++() 
{
    increaseDay();
    return *this;
}
Date Date::operator++(int) 
{
    Date temp(*this);
    increaseDay();
    return temp;
}

Date& Date::operator--() 
{
    _day--;
    normalize();
    return *this;
}
Date Date::operator--(int) 
{
    Date temp(*this);
    _day--;
    normalize();
    return temp;
}

Date& Date::operator+=(int days) 
{
    _day += days;
    normalize();
    return *this;
}
Date& Date::operator-=(int days) 
{
    _day -= days;
    normalize();
    return *this;
}

Date& Date::operator=(const Date& other) 
{
    if (this != &other) 
    {
        _day = other._day;
        _month = other._month;
        _year = other._year;
    }

    return *this;
}

std::string Date::operator()() const 
{
    std::string result;

    if (_day < 10) result += "0";
    result += std::to_string(_day);
    result += ".";

    if (_month < 10) result += "0";
    result += std::to_string(_month);
    result += ".";

    if (_year < 10) result += "000";
    else if (_year < 100) result += "00";
    else if (_year < 1000) result += "0";
    result += std::to_string(_year);

    return result;
}



bool operator==(const Date& date1, const Date& date2) 
{
    return date1._day == date2._day && date1._month == date2._month && date1._year == date2._year;        
}
bool operator!=(const Date& date1, const Date& date2)
{
    return !(date1 == date2);
}

bool operator<(const Date& date1, const Date& date2)
{
    if (date1._year != date2._year) return date1._year < date2._year;
    if (date1._month != date2._month) return date1._month < date2._month;
    return date1._day < date2._day;
}
bool operator>(const Date& date1, const Date& date2)
{
    return date2 < date1;
}

bool operator<=(const Date& date1, const Date& date2)
{
    return !(date1 > date2);
}
bool operator>=(const Date& date1, const Date& date2) 
{
    return !(date1 < date2);
}



ostream& operator<<(ostream& stream, const Date& date) 
{
    stream << setfill('0') << setw(2) << date._day << "." << setw(2) << date._month << "." << setw(4) << date._year;
       
    return stream;
}
istream& operator>>(istream& stream, Date& date) 
{
    char dot1, dot2;
    int day, month, year;

    stream >> day >> dot1 >> month >> dot2 >> year;

    if (dot1 != '.' || dot2 != '.') {
        stream.setstate(ios::failbit);
        return stream;
    }

    return stream;
}