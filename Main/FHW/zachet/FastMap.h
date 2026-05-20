#pragma once

#include "Color.h"

#include <vector>
#include <cstdint>
#include <stdexcept>
#include <bit>
#include <algorithm>
#include <iostream>

class FastMap
{
public:
     FastMap() = delete;
     FastMap(int width, int height) : _width(width), _height(height)
    {
        if (width <= 0 || height <= 0)
        {
            throw std::invalid_argument("Width and height must be positive");
        }

        _stride = (_width + 63) / 64;  
        data.resize(_height * _stride, 0);
    }
    ~FastMap() = default;

    void setStatus(int x, int y, bool alive);
    bool getStatus(int x, int y) const;

    void clear();

    int getWidth () const { return _width;  }
    int getHeight() const { return _height; }
    int getStride() const { return _stride; }

    int countAlive() const;
    int countNeighbors(int x, int y) const;

    void update();

    void print() const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

private:
    std::vector<uint64_t> data;
    int _width;
    int _height;
    int _stride;

    int getIndex(int x, int y) const;
    int getBitPos(int x) const;

};

