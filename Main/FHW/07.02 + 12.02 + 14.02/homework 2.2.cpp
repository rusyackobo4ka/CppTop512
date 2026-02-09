#include <iostream>

class flat
{
private:
    std::string _square;
    int _price;
public:
    flat() : _square(" "), _price(0) {}
    flat(std::string type, int price) : _square(type), _price(price) {}
    ~flat() {}

    flat(flat& item)
    {
        _square = item.getSquare();
        _price = item.getPrice();
    }
    flat(flat&& item)
    {
        _square = item.getSquare();
        _price = item.getPrice();
    }

    void setFlat(std::string type, int price)
    {
        _square = type;
        _price = price;
    }

    std::string getSquare()
    {
        return _square;
    }

    int getPrice()
    {
        return _price;
    }

    bool operator== (flat& item)
    {
        return (_square == item.getSquare());   
    }
    void operator= (flat& item)
    {
        _square = item.getSquare();
        _price = item.getPrice();
    }
    bool operator> (flat& item)
    {
            return _price > item.getPrice(); 
    }
    bool operator< (flat& item)
    {
        return _price < item.getPrice();
    }
    bool operator>= (flat& item)
    {
        return _price >= item.getPrice();
    }
    bool operator<= (flat& item)
    {
        return _price <= item.getPrice();
    }
};


int main()
{
    

    return 1;
}

