#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

class FileHandler 
{
public:
    FileHandler() {}

    virtual ~FileHandler() 
    {
        if (file.is_open()) 
        {
            file.close();
        }
    }

    virtual void Display(const char* path);

    bool fileExists(const char* path) 
    {
        std::ifstream file(path);
        return file.good();
    }

protected:
    std::string fileName;
    std::ifstream file;

    bool openFile(const char* path);
};

class HexFileHandler : public FileHandler 
{
public:
    void Display(const char* path) override 
    {
        if (!openFile(path)) 
        {
            return;
        }

        std::cout << "Файл: " << fileName << std::endl;

        unsigned char buffer[16];
        int offset = 0;

        while (file.read(reinterpret_cast<char*>(buffer), sizeof(buffer)) || file.gcount() > 0) 
        {
            std::cout << std::setw(8) << std::setfill('0') << std::hex << offset << ": ";

            int bytesRead = file.gcount();
            for (int i = 0; i < 16; ++i) 
            {
                if (i < bytesRead) 
                {
                    std::cout << std::setw(2) << std::setfill('0') << std::hex
                        << static_cast<int>(buffer[i]) << " ";
                }
                else 
                {
                    std::cout << "   ";
                }

                if (i == 7) std::cout << " ";
            }

            // Выводим ASCII представление
            std::cout << " |";
            for (int i = 0; i < bytesRead; ++i) 
            {
                if (buffer[i] >= 32 && buffer[i] <= 126) 
                {
                    std::cout << static_cast<char>(buffer[i]);
                }
                else 
                {
                    std::cout << '.';
                }
            }
            std::cout << "|" << std::endl;

            offset += bytesRead;
        }

        file.close();
    }
};

// Второй класс потомок - показывает содержимое в двоичном виде
class BinaryFileHandler : public FileHandler 
{
public:
    void Display(const char* path) override 
    {
        if (!openFile(path)) 
        {
            return;
        }

        std::cout << "Файл: " << fileName << std::endl;

        unsigned char byte;
        int byteCount = 0;
        const int bytesPerLine = 8; // По 8 байт в строке для удобства чтения

        while (file.read(reinterpret_cast<char*>(&byte), 1)) 
        {
            // Выводим двоичное представление байта
            for (int i = 7; i >= 0; --i) 
            {
                std::cout << ((byte >> i) & 1);
            }
            std::cout << " ";

            byteCount++;

            // Новая строка через каждые 8 байт
            if (byteCount % bytesPerLine == 0) 
            {
                std::cout << std::endl;
            }
        }

        std::cout << "\n\nВсего байт: " << byteCount << std::endl;
        file.close();
    }
};
