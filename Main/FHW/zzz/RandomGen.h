#pragma once

#include <random>

class RandomGen
{

public:
    RandomGen()
    {
        std::random_device rd;
        gen.seed(rd());
    }

    int getRNum(int min, int max) 
    {
        std::uniform_int_distribution<> dis(min, max);
        return dis(gen);
    }
private:
    std::mt19937 gen;
};
