#pragma once
#include <cmath>
#include <iostream>
class drob
{
public:
    drob() : _up(0), _down(1) {}

    drob(double up, double down) : _up(up), _down(down) {}

    ~drob() {}

    void setDrob(const double& up, const double& down)
    {
        _up = up;
        _down = down;
    }

    double getDrobUp()
    {
        return _up;
    }

    double getDrobDown()
    {
        return _down;
    }

private:
    double _up;
    double _down;
};

class complexNumber
{
public:
    complexNumber() : _realNum(0), _imageNum(0) {}
    complexNumber(double realNum, double imageNum) : _realNum(realNum), _imageNum(imageNum) {}
    complexNumber(complexNumber& number)
    {
        _realNum = number._realNum;
        _imageNum = number._imageNum;
    }
    complexNumber(complexNumber&& number)
    {
        _realNum = number._realNum;
        _imageNum = number._imageNum;
    }
    ~complexNumber() {}

    complexNumber& operator++ ();
    complexNumber& operator-- ();
    bool operator== (complexNumber&) const;
    bool operator!= (complexNumber&) const;
    bool operator> (complexNumber&) const;
    bool operator>= (complexNumber&) const;
    bool operator< (complexNumber&) const;
    bool operator<= (complexNumber&) const;

    complexNumber operator+ (complexNumber&) const;
    complexNumber operator+ (double&) const;
    complexNumber operator+ (drob&) const;


    complexNumber operator- (complexNumber&) const;
    complexNumber operator- (double&) const;
    complexNumber operator- (drob&) const;


    complexNumber operator* (complexNumber&) const;
    complexNumber operator* (double&) const;
    complexNumber operator* (drob&) const;


    complexNumber operator/ (complexNumber&) const;
    complexNumber operator/ (double&) const;
    complexNumber operator/ (drob&) const;

    void setCompNum(const double& realNum, const double& imageNum)
    {
        _realNum = realNum;
        _imageNum = imageNum;
    }

    double getRealNum()
    {
        return _realNum;
    }

    double getImageNum()
    {
        return _imageNum;
    }

    void printCompNum()
    {
        std::cout << '(' << _realNum << " + " << _imageNum << "i" << ')';
    }

    static complexNumber multi(complexNumber compNum, drob num)
    {
        complexNumber result;

        result._realNum = compNum._realNum * num.getDrobUp() / num.getDrobDown();
        result._imageNum = compNum._imageNum * num.getDrobUp() / num.getDrobDown();

        return result;
    }

private:
	double _realNum;
    double _imageNum;
};


