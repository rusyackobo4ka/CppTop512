#include "GameOfLife.h"

#include "FastMap.h"
#include "RandomGen.h"
#include "Color.h"

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <conio.h> 
#include <algorithm>
#include <windows.h>

void GameOfLife::update()
{
    for (int y = 0; y < _current.getHeight(); y++)
    {
        for (int x = 0; x < _current.getWidth(); x++)
        {
            int neighbors = _current.countNeighbors(x, y);
            bool isAlive = _current.getStatus(x, y);

            if (isAlive &&
                (neighbors == 2 ||  
                 neighbors == 3)
                )
            {
                _next.setStatus(x, y, true);
            }
            else if (!isAlive &&
                      neighbors == 3)
            {
                _next.setStatus(x, y, true);
            }
            else
            {
                _next.setStatus(x, y, false);
            }
        }
    }

    std::swap(_current, _next);
    _next.clear();
    }

void GameOfLife::fillRandom(double percent)
{
    if (percent > 100 || percent < 0)
        throw std::invalid_argument("Percent must be in 0-100");

    RandomGen rnd;

    #define mapSize(map) (map.getHeight() * map.getWidth())

    for (int i = 0; i < mapSize(_current) * percent / 100; ++i)
    {
        _current.setStatus(rnd.getRNum(0, _current.getWidth() - 1), rnd.getRNum(0, _current.getHeight() - 1), 1);
    }    
}

void GameOfLife::displayGuide()
{
    std::cout << "SPACE = Pause " << "-/+ = Speed " << "r = Restart" << "q = Quit" << "\n";
}
void GameOfLife::displayStat(const FastMap& map, int generation, int aliveCount)
{
    std::cout << "Generation: " << generation << "\n";     
    std::cout << "Alive cells: " << aliveCount << "\n";
    std::cout << "Speed: " << 500 - _delayMs << "\n";
}
void GameOfLife::displayMap(const FastMap& map)
{
    system("cls");

    for (int y = 0; y < map.getHeight(); y++)
    {
        for (int x = 0; x < map.getWidth(); x++)
        {
            if (map.getStatus(x, y))
            {
                std::cout << Color::GREEN << Color::BOLD << "█" << Color::RESET;
            }
            else
            {
                std::cout << Color::WHITE << "·" << Color::RESET;
            }
        }
        std::cout << "\n";
    }
}
void GameOfLife::displayMapC(const FastMap& map)
{
    system("cls");

    for (int y = 0; y < map.getHeight(); y++)
    {
        for (int x = 0; x < map.getWidth(); x++)
        {
            if (map.getStatus(x, y))
            {
                if (map.countNeighbors(x, y) == 2)
                {
                    std::cout << Color::YELLOW << "●" << Color::RESET;
                }
                else if (map.countNeighbors(x, y) == 3)
                {  
                    std::cout << Color::RED << "●" << Color::RESET;
                }
                else
                {
                    std::cout << Color::GREEN << Color::BOLD << "●" << Color::RESET;
                }
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}
void GameOfLife::displayAll(const FastMap& map, int generation, int aliveCount)
{
    displayMapC(map);
    displayStat(map, generation, aliveCount);
    displayGuide();
}

void GameOfLife::helloScreen()
{
    std::cout << "Enter the number of percentages to fill in the field: ";
    int answer;
    std::cin >> answer;
    if (answer > 100 || answer <= 0)
    {
        answer = 0;
    }

    fillRandom(answer);
}

void GameOfLife::run(FastMap& map)
{
    int generation = 0;

    while (_isRunning)
    {
        handleInput();

        if (_isRestart)
        {
            _current.clear();
            _next.clear();
            generation = 0;

            helloScreen();

            _isRestart = false;
        }

        if (!_isPause)
        {
            displayAll(map, generation, map.countAlive());
            update();
            generation++;

            std::this_thread::sleep_for(std::chrono::milliseconds(_delayMs));
        }
        else
        {
            displayAll(map, generation, map.countAlive());
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
}

void GameOfLife::handleInput()
{
    if (_kbhit())
    {
        char key = _getch();
        switch (key)
        {
        case ' ':
            _isPause = !_isPause;
            break;
        case '+':
            _delayMs = (std::max)(10, _delayMs - 10);
            break;
        case '-':
            _delayMs = (std::min)(500, _delayMs + 10);
            break;
        case 'r':
            _isRestart = true;
            break;
        case 'q':
            _isRunning = false;
            break;
        }
    }
}

