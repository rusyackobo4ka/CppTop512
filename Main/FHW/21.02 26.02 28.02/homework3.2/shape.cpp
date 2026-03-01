#include "shape.h"

void Square::Show() const
{
    std::cout << "Square: topLeft(" << _topLeft.getX() << "," << _topLeft.getY() << "), side=" << _side << std::endl;
}

void Square::Save(const std::string& filename) const
{
    std::ofstream file(filename, std::ios::app);
    if (file.is_open())
    {
        file << "Square " << _topLeft.getX() << " " << _topLeft.getY() << " " << _side << "\n";
        file.close();
    }
}

void Square::Load(const std::string& filename)
{
    std::ifstream file(filename);
    if (file.is_open())
    {
        std::string type;
        file >> type;
        if (type == "Square")
        {
            int x, y;
            file >> x >> y >> _side;
            _topLeft = Point(x, y);
        }
        file.close();
    }
}

void Rectangle::Show() const
{
    std::cout << "Rectangle: topLeft(" << _topLeft.getX() << "," << _topLeft.getY() << "), width=" << _width << ", height=" << _height << std::endl;
}

void Rectangle::Save(const std::string& filename) const
{
    std::ofstream file(filename, std::ios::app);
    if (file.is_open())
    {
        file << "Rectangle " << _topLeft.getX() << " " << _topLeft.getY()
            << " " << _width << " " << _height << "\n";
        file.close();
    }
}

void Rectangle::Load(const std::string& filename)
{
    std::ifstream file(filename);
    if (file.is_open())
    {
        std::string type;
        file >> type;
        if (type == "Rectangle")
        {
            int x, y;
            file >> x >> y >> _width >> _height;
            _topLeft = Point(x, y);
        }
        file.close();
    }
}

void Circle::Show() const
{
    std::cout << "Circle: center(" << _center.getX() << "," << _center.getY() << "), radius=" << _radius << std::endl;
}

void Circle::Save(const std::string& filename) const
{
    std::ofstream file(filename, std::ios::app);
    if (file.is_open())
    {
        file << "Circle " << _center.getX() << " " << _center.getY() << " " << _radius << "\n";
        file.close();
    }
}

void Circle::Load(const std::string& filename)
{
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string type;
        file >> type;
        if (type == "Circle") {
            int x, y;
            file >> x >> y >> _radius;
            _center = Point(x, y);
        }
        file.close();
    }
}

void Ellipse::Show() const
{
    std::cout << "Ellipse: boundingRect topLeft(" << _topLeft.getX() << "," << _topLeft.getY() << "), width=" << _width << ", height=" << _height << std::endl;
}

void Ellipse::Save(const std::string& filename) const
{
    std::ofstream file(filename, std::ios::app);
    if (file.is_open())
    {
        file << "Ellipse " << _topLeft.getX() << " " << _topLeft.getY() << " " << _width << " " << _height << "\n";
        file.close();
    }
}

void Ellipse::Load(const std::string& filename)
{
    std::ifstream file(filename);
    if (file.is_open())
    {
        std::string type;
        file >> type;
        if (type == "Ellipse")
        {
            int x, y;
            file >> x >> y >> _width >> _height;
            _topLeft = Point(x, y);
        }
        file.close();
    }
}