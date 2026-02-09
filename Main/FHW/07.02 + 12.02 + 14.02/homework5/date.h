#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <stdexcept>

class Date 
{
private:
    int _day;
    int _month;
    int _year;
    
    bool isLeapYear(int year) const;
    int daysInMonth(int month, int year) const;
    void normalize(); 
    
public:
    Date();                          
    Date(int day, int month, int year);
    Date(const Date& other);        
    
    int getDay() const { return _day;}
    int getMonth() const { return _month;}
    int getYear() const { return _year;}
    
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    void setDate(int day, int m, int year);
    
    void increaseDay();
    
    Date& operator++();               
    Date operator++(int); 

    Date& operator--();               
    Date operator--(int);             
    
    Date& operator+=(int days);       
    Date& operator-=(int days);       
    
    Date& operator=(const Date& other);

    std::string operator()() const;



    friend bool operator==(const Date& date1, const Date& date2);
    friend bool operator!=(const Date& date1, const Date& date2);

    friend bool operator<(const Date& date1, const Date& date2);
    friend bool operator>(const Date& date1, const Date& date2);

    friend bool operator<=(const Date& date1, const Date& date2);
    friend bool operator>=(const Date& date1, const Date& date2);

    friend std::ostream& operator<<(std::ostream& stream, const Date& date);
    friend std::istream& operator>>(std::istream& stream, Date& date);
};

#endif 
