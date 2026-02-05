#ifndef STRING_H
#define STRING_H

#include <iostream>

class String {
private:
    char* data;           
    size_t length;        
    size_t capacity;

    static int objectCount; 

    void allocateMemory(size_t size);
    void copyFrom(const char* source);

public:
    String();                                  
    String(size_t size);               
    String(const char* str);                   
    String(const String& other);                
    String(String&& other);         

    ~String();

    String& operator=(const String& other);

    void input();                             
    void output() const;                       

    size_t getLength() const { return length; }
    const char* c_str() const { return data; }

    char& operator[](size_t index);
    const char& operator[](size_t index) const;

    static int getObjectCount() { return objectCount; }

    void clear();
    bool isEmpty() const 
    { 
        return length == 0; 
    }

    friend std::ostream& operator<<(std::ostream& os, const String& str);
    friend std::istream& operator>>(std::istream& is, String& str);
};

int String::objectCount = 0;

#endif