#include <iostream>

#include "shape.h"
// 21.02 26.02 28.02


int main()
{
    std::vector<std::unique_ptr<Shape>> shapes;

    shapes.push_back(std::make_unique<Square>(Point(10, 10), 5));
    shapes.push_back(std::make_unique<Rectangle>(Point(20, 20), 8, 4));
    shapes.push_back(std::make_unique<Circle>(Point(30, 30), 3));
    shapes.push_back(std::make_unique<Ellipse>(Point(40, 40), 10, 6));

    std::cout << "\nSave to 'shapes.txt'..." << std::endl;

    for (int i = 0; i < shapes.size(); ++i) 
    {
        shapes[i]->Save("shapes.txt");
    }

    std::vector<std::unique_ptr<Shape>> loadedShapes;
    std::ifstream file("shapes.txt");

    if (file.is_open()) 
    {
        std::string type;
        while (file >> type) 
        {
            if (type == "Square") 
            {
                auto square = std::make_unique<Square>();
                file.seekg(-(long)(type.length() + 1), std::ios::cur);
                square->Load("shapes.txt");
                loadedShapes.push_back(std::move(square));
            }
            else if (type == "Rectangle") 
            {
                file.seekg(-(long)(type.length() + 1), std::ios::cur);
                auto rect = std::make_unique<Rectangle>();
                rect->Load("shapes.txt");
                loadedShapes.push_back(std::move(rect));
            }
            else if (type == "Circle") 
            {
                file.seekg(-(long)(type.length() + 1), std::ios::cur);
                auto circle = std::make_unique<Circle>();
                circle->Load("shapes.txt");
                loadedShapes.push_back(std::move(circle));
            }
            else if (type == "Ellipse") 
            {
                file.seekg(-(long)(type.length() + 1), std::ios::cur);
                auto ellipse = std::make_unique<Ellipse>();
                ellipse->Load("shapes.txt");
                loadedShapes.push_back(std::move(ellipse));
            }
        }
        file.close();
    }

    std::cout << "load: " << std::endl;
    for (int i = 0; i < shapes.size(); ++i)
    {
        shapes[i]->Show();
    }
}
