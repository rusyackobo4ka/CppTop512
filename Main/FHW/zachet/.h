#pragma once
#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>

class SmoothConsole 
{
private:
    HANDLE hConsole;
    int width, height;
    CHAR_INFO* backBuffer;
    CHAR_INFO* frontBuffer;

    void gotoxy(int x, int y) 
    {
        COORD coord = { (SHORT)x, (SHORT)y };
        SetConsoleCursorPosition(hConsole, coord);
    }

public:
    SmoothConsole(int w, int h) : width(w), height(h) 
    {
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        // Скрываем курсор
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(hConsole, &cursorInfo);
        cursorInfo.bVisible = false;
        SetConsoleCursorInfo(hConsole, &cursorInfo);

        // Устанавливаем размер окна
        COORD bufferSize = { (SHORT)width, (SHORT)height };
        SetConsoleScreenBufferSize(hConsole, bufferSize);

        // Выделяем буферы
        backBuffer = new CHAR_INFO[width * height];
        frontBuffer = new CHAR_INFO[width * height];

        clear();
    }

    ~SmoothConsole() 
    {
        delete[] backBuffer;
        delete[] frontBuffer;
    }

    void clear() {
        for (int i = 0; i < width * height; i++) 
        {
            backBuffer[i].Char.AsciiChar = ' ';
            backBuffer[i].Attributes = 7;
        }
    }

    void setPixel(int x, int y, char ch, int color) 
    {
        if (x >= 0 && x < width && y >= 0 && y < height) 
        {
            int idx = y * width + x;
            backBuffer[idx].Char.AsciiChar = ch;
            backBuffer[idx].Attributes = color;
        }
    }

    void render() {
        // Рисуем только изменившиеся пиксели
        for (int i = 0; i < width * height; i++) 
        {
            if (backBuffer[i].Char.AsciiChar != frontBuffer[i].Char.AsciiChar ||
                backBuffer[i].Attributes != frontBuffer[i].Attributes) {

                int x = i % width;
                int y = i / width;

                gotoxy(x, y);
                std::cout << backBuffer[i].Char.AsciiChar;

                frontBuffer[i] = backBuffer[i];
            }
        }

        gotoxy(0, 0);
    }

    void setFPS(int fps) 
    {
        static auto lastFrame = std::chrono::steady_clock::now();
        int frameTime = 1000 / fps;

        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastFrame);

        if (elapsed.count() < frameTime) {
            std::this_thread::sleep_for(std::chrono::milliseconds(frameTime - elapsed.count()));
        }

        lastFrame = std::chrono::steady_clock::now();
    }
};

