#include "String.h"
#include <cstring>
#include <iostream>
#include <limits>

using namespace std;

void String::allocateMemory(size_t size) 
{
    capacity = size + 1; 
    data = new char[capacity];
    data[0] = '\0';
    length = 0;
}

void String::copyFrom(const char* source) 
{
    if (!source) {
        length = 0;
        data[0] = '\0';
        return;
    }

    length = strlen(source);
}

String::String() : String(80) {}

String::String(size_t size) 
{
    allocateMemory(size);
    objectCount++;
}

String::String(const char* str) : String(strlen(str)) 
{
    copyFrom(str);
}

String::String(const String& other) : String(other.length) 
{
    copyFrom(other.data);
}

String::String(String&& other) : data(other.data), length(other.length), capacity(other.capacity) 
{
    other.data = nullptr;
    other.length = 0;
    other.capacity = 0;
    objectCount++;
}

String::~String() 
{
    delete[] data;
    objectCount--;
}

String& String::operator=(const String& other) 
{
    if (this != &other) 
    {
        copyFrom(other.data);
    }
    return *this;
}

void String::input() 
{
    cout << "Введите строку (макс. " << capacity - 1 << " символов): ";

    cin.getline(data, capacity);
    length = strlen(data);
}

void String::output() const 
{
    cout << data;
}

char& String::operator[](size_t index) 
{
    return data[index];
}

const char& String::operator[](size_t index) const 
{
    return data[index];
}

void String::clear() 
{
    data[0] = '\0';
    length = 0;
}

ostream& operator<<(ostream& os, const String& str) 
{
    os << str.data;
    return os;
}

istream& operator>>(istream& is, String& str) 
{
    const size_t BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];

    is.getline(buffer, BUFFER_SIZE);
    str = buffer;  

    return is;
}