#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <memory>

class Equation
{
public:
    Equation(const std::string& type = "Abstract") : equationType(type) {}

    virtual ~Equation() {}

    virtual std::vector<double> findRoots() const = 0;

    virtual void printEquation() const = 0;

    void printRoots() const;

    std::string getType() const { return equationType; }

protected:
    std::string equationType;

};

class LinearEquation : public Equation 
{
public:
    LinearEquation(double A, double B) : Equation("Linear"), _a(A), _b(B) {}

    std::vector<double> findRoots() const override 
    {
        std::vector<double> roots;

        if (_a == 0) 
        {  
            if (_b == 0) 
            {  
                std::cout << "  infinity" << std::endl;
            }
        }
        else 
        {
            roots.push_back(-_b / _a);
        }

        return roots;
    }

    void printEquation() const override 
    {
        if (_a == 0) 
        {
            std::cout << _b << " = 0";
        }
        else 
        {
            std::cout << _a << "x ";
            if (_b >= 0) 
            {
                std::cout << "+ " << _b << " = 0";
            }
            else 
            {
                std::cout << "- " << -_b << " = 0";
            }
        }
    }

    double getA() const { return _a; }
    double getB() const { return _b; }

private:
    double _a;
    double _b;
};

// Класс квадратного уравнения (ax? + bx + c = 0)
class QuadraticEquation : public Equation {
private:
    double a;
    double b;
    double c;

public:
    QuadraticEquation(double coeffA, double coeffB, double coeffC)
        : Equation("Quadratic"), a(coeffA), b(coeffB), c(coeffC) {
    }

    std::vector<double> findRoots() const override {
        std::vector<double> roots;

        // Проверка, не вырождается ли в линейное уравнение
        if (std::abs(a) < 1e-10) {
            LinearEquation linear(b, c);
            return linear.findRoots();
        }

        // Вычисление дискриминанта
        double discriminant = b * b - 4 * a * c;

        if (discriminant < -1e-10) {  // Отрицательный дискриминант
            // Нет действительных корней
            return roots;
        }
        else if (std::abs(discriminant) < 1e-10) {  // Дискриминант = 0
            // Один корень (два одинаковых)
            double root = -b / (2 * a);
            roots.push_back(root);
        }
        else {  // Дискриминант > 0
            // Два корня
            double sqrtDiscriminant = std::sqrt(discriminant);
            double root1 = (-b + sqrtDiscriminant) / (2 * a);
            double root2 = (-b - sqrtDiscriminant) / (2 * a);
            roots.push_back(root1);
            roots.push_back(root2);
        }

        return roots;
    }

    void printEquation() const override {
        if (std::abs(a) < 1e-10) {
            LinearEquation linear(b, c);
            linear.printEquation();
            return;
        }

        std::cout << a << "x? ";

        if (std::abs(b) > 1e-10) {
            if (b > 0) {
                std::cout << "+ " << b << "x ";
            }
            else {
                std::cout << "- " << -b << "x ";
            }
        }

        if (std::abs(c) > 1e-10) {
            if (c > 0) {
                std::cout << "+ " << c;
            }
            else {
                std::cout << "- " << -c;
            }
        }

        std::cout << " = 0";
    }

    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }
};

