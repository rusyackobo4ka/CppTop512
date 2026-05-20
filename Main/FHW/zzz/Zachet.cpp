#include "GameOfLife.h"
#include "RandomGen.h"

#include <iostream>
#include <windows.h>

void optimizeConsole() 
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Отключаем быстрый режим (иногда помогает)
    SetConsoleMode(hConsole, ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    // Устанавливаем размер буфера
    COORD bufferSize = { 120, 100 };
    SetConsoleScreenBufferSize(hConsole, bufferSize);

    // Скрываем курсор
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    // Отключаем выделение окна
    HWND hwnd = GetConsoleWindow();
    LONG style = GetWindowLong(hwnd, GWL_STYLE);
    style &= ~(WS_SIZEBOX);  // Убираем изменение размера
    SetWindowLong(hwnd, GWL_STYLE, style);
} 

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int Width = 100, Height = 50;

    GameOfLife Game(Width, Height);

    Game.helloScreen();

    optimizeConsole();

    Game.run(Game.getMap());
    

    return 0;
}

