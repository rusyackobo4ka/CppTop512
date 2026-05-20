#include "FastMap.h"

#include "Color.h"

#include <vector>
#include <cstdint>
#include <stdexcept>
#include <bit>
#include <algorithm>
#include <iostream>

int FastMap::getIndex(int x, int y) const
{
    if (x < 0 || x >= _width || y < 0 || y >= _height)
    {
        throw std::out_of_range("Coordinates out of bounds");
    }

    return y * _stride + (x / 64);
}
int FastMap::getBitPos(int x) const
{
    return x % 64;
}

void FastMap::setStatus(int x, int y, bool alive)
{
    int index = getIndex(x, y);
    int bit = getBitPos(x);

    if (alive)
    {
        data[index] |= (1ULL << bit);
    }
    else
    {
        data[index] &= ~(1ULL << bit);
    }
}
bool FastMap::getStatus(int x, int y) const
{
    int index = getIndex(x, y);
    int bit = getBitPos(x);

    return (data[index] >> bit) & 1;
}

void FastMap::clear()
{
    std::fill(data.begin(), data.end(), 0);
}

int FastMap::countAlive() const
{
    int count = 0;

    for (uint64_t val : data)
    {
        count += std::popcount(val);
    }
    return count;
}
int FastMap::countNeighbors(int x, int y) const
{
    int count = 0;

    for (int moveY = -1; moveY <= 1; ++moveY)
    {
        for (int moveX = -1; moveX <= 1; ++moveX)
        {
            if (moveX == 0 && moveY == 0) continue;

            int tmpX = x + moveX;
            int tmpy = y + moveY;

            if (tmpX >= 0     && 
                tmpX < _width &&
                tmpy >= 0     && 
                tmpy < _height)
            {
                if (getStatus(tmpX, tmpy)) ++count;
            }
        }
    }
    return count;
}

void FastMap::update()
{
    std::vector<uint64_t> newData(data.size(), 0);

    for (int y = 0; y < _height; ++y)
    {
        for (int segment = 0; segment < _stride; ++segment)
        {
            uint64_t current = data[y * _stride + segment];

            if (current == 0 &&
                segment > 0  &&
                segment < _stride - 1)
            {
                continue;
            }

            int startBit = segment * 64;
            int endBit = std::min(startBit + 64, _width);

            for (int bit = 0; bit < (endBit - startBit); ++bit)
            {
                if (!((current >> bit) & 1) &&
                    segment > 0             &&
                    segment < _stride - 1)
                {
                    continue;
                }

                int x = startBit + bit;
                int neighbors = countNeighbors(x, y);
                bool alive = getStatus(x, y);

                int newIndex = y * _stride + segment;
                int newBitPos = bit;

                if (alive)
                {
                    if (neighbors == 2 || neighbors == 3)
                    {
                        newData[newIndex] |= (1ULL << newBitPos);
                    }
                }
                else
                {
                    if (neighbors == 3)
                    {
                        newData[newIndex] |= (1ULL << newBitPos);
                    }
                }
            }
        }
    }

    data = std::move(newData);
}

void FastMap::print() const
{
    for (int y = 0; y < _height; y++)
    {
        for (int x = 0; x < _width; x++)
        {
            std::cout << (getStatus(x, y) ? "#" : " ");
        }
        std::cout << "\n";
    }
}

void FastMap::saveToFile(const std::string& filename) const
{
    FILE* file = nullptr;

    errno_t err = fopen_s(&file, filename.c_str(), "wb");

    if (err != 0 || file == nullptr)
    {
        std::cerr << "Не удалось открыть файл для записи: " << filename << "\n";
        return;
    }


    fwrite(&_height, sizeof(int), 1, file);
    fwrite(data.data(), sizeof(uint64_t), data.size(), file);

    fclose(file);
}
void FastMap::loadFromFile(const std::string& filename)
{
    FILE* file = nullptr;
    errno_t err = fopen_s(&file, filename.c_str(), "rb");

    if (err != 0 || file == nullptr)
    {
        std::cerr << "Не удалось открыть файл для чтения: " << filename << "\n";
        return;
    }

    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    if (width != _width || height != _height)
    {
        fclose(file);
        throw std::runtime_error("File dimensions don't match grid size");
    }

    fread(data.data(), sizeof(uint64_t), data.size(), file);
    fclose(file);
}
