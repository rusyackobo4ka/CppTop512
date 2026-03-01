#include "FileWork.h"

void FileHandler::Display(const char* path)
{
    if (!openFile(path))
    {
        return;
    }

    std::cout << "Τΰιλ: " << fileName << std::endl;

    std::string line;

    while (std::getline(file, line)) 
    {
        std::cout << line << std::endl;
    }

    file.close();
}

bool FileHandler::openFile(const char* path)
{
    if (file.is_open())
    {
        file.close();
    }

    file.open(path, std::ios::binary);

    if (!file.is_open())
    {
        return false;
    }

    fileName = path;
    return true;
}
