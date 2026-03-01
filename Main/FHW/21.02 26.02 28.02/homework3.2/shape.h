#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include <cmath>

class Point 
{
private:
    int _x, _y;
public:
    Point(int x = 0, int y = 0) : _x(x), _y(y) {}
    ~Point() = default;

    int getX() const { return _x; }
    int getY() const { return _y; }
    void setX(int newX) { _x = newX; }
    void setY(int newY) { _y = newY; }
};

class Shape 
{
public:
    virtual ~Shape() {}
    virtual void Show() const = 0;      
    virtual void Save(const std::string& filename) const = 0;  
    virtual void Load(const std::string& filename) = 0;      
};

class Square : public Shape 
{
private:
    Point _topLeft;     
    int _side;         

public:
    Square(const Point& topLeft = Point(0, 0), int side = 1) : _topLeft(topLeft), _side(side) {}

    void Show() const override;  
    void Save(const std::string& filename) const override;
    void Load(const std::string& filename) override;
    
};

class Rectangle : public Shape 
{
private:
    Point _topLeft;    
    int _width;        
    int _height;       

public:
    Rectangle(const Point& topLeft = Point(0, 0), int width = 1, int height = 1) : _topLeft(topLeft), _width(width), _height(height) {}
        
    void Show() const override;
    void Save(const std::string& filename) const override;
    void Load(const std::string& filename) override;
};

class Circle : public Shape 
{
private:
    Point _center;      
    int _radius;        

public:
    Circle(const Point& center = Point(0, 0), int radius = 1) : _center(center), _radius(radius) {}

    void Show() const override;
    void Save(const std::string& filename) const override;
    void Load(const std::string& filename) override;
};

class Ellipse : public Shape 
{
private:
    Point _topLeft;    
    int _width;        
    int _height;        

public:
    Ellipse(const Point& topLeft = Point(0, 0), int width = 1, int height = 1) : _topLeft(topLeft), _width(width), _height(height) {}

    void Show() const override;
    void Save(const std::string& filename) const override;
    void Load(const std::string& filename) override; 
};
