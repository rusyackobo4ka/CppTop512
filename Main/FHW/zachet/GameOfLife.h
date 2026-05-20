#pragma once

#include "FastMap.h"
#include "RandomGen.h"
#include "Color.h"

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <conio.h> 
#include <algorithm>

class GameOfLife 
{
public:
     GameOfLife() = delete;
     GameOfLife(int width, int height) : _current(width, height), _next(width, height) {}
    ~GameOfLife() = default;

    void update();

    void fillRandom(double count);

    FastMap& getMap() { return _current; }

    void displayGuide();
    void displayStat(const FastMap& map, int generation, int aliveCount);
    void displayMap(const FastMap& map);
    void displayMapC(const FastMap& map);
    void displayAll(const FastMap& map, int generation, int aliveCount);

    void helloScreen();

    void run(FastMap& game);

private:
    FastMap _current;
    FastMap _next;
    
    bool _isRestart = false;
    bool _isRunning = true;
    bool _isPause = false;
    int _delayMs = 400;

    void handleInput();
};

