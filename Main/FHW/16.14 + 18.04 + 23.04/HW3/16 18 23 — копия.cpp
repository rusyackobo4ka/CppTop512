#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include <algorithm>

std::string toLower(const std::string& str) 
{
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Функция для очистки слова от знаков пунктуации
std::string cleanWord(const std::string& word) {
    std::string result;
    for (char ch : word) {
        if (std::isalnum(static_cast<unsigned char>(ch)) || ch == '\'' || ch == '-') {
            result += ch;
        }
    }
    return result;
}

int main() {
    std::string inputFileName, outputFileName;

    std::cout << "Введите имя входного файла: ";
    std::cin >> inputFileName;

    std::cout << "Введите имя выходного файла: ";
    std::cin >> outputFileName;

    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл " << inputFileName << std::endl;
        return 1;
    }

    std::map<std::string, int> wordFrequency;
    std::string word;

    // Чтение слов из файла
    while (inputFile >> word) {
        // Приводим к нижнему регистру и очищаем от пунктуации
        std::string cleanedWord = cleanWord(toLower(word));

        // Игнорируем пустые строки
        if (!cleanedWord.empty()) {
            wordFrequency[cleanedWord]++;
        }
    }

    inputFile.close();

    if (wordFrequency.empty()) {
        std::cout << "Файл не содержит слов или пуст." << std::endl;
        return 0;
    }

    // Вывод информации обо всех словах
    std::cout << "\n=== ЧАСТОТНЫЙ СЛОВАРЬ ===" << std::endl;
    std::cout << "Всего уникальных слов: " << wordFrequency.size() << std::endl;
    std::cout << "\nСлово : Частота" << std::endl;
    std::cout << "-------------------" << std::endl;

    for (const auto& pair : wordFrequency) {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }

    // Поиск наиболее часто встречающегося слова
    std::string mostFrequentWord;
    int maxFrequency = 0;

    for (const auto& pair : wordFrequency) {
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
            mostFrequentWord = pair.first;
        }
    }

    // Вывод информации о наиболее часто встречающемся слове
    std::cout << "\n=== НАИБОЛЕЕ ЧАСТОЕ СЛОВО ===" << std::endl;
    std::cout << "Слово: \"" << mostFrequentWord << "\"" << std::endl;
    std::cout << "Встречается: " << maxFrequency << " раз(а)" << std::endl;

    // Запись результата в файл
    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        std::cerr << "Ошибка: не удалось создать файл " << outputFileName << std::endl;
        return 1;
    }

    outputFile << "Частотный словарь для файла: " << inputFileName << std::endl;
    outputFile << "=========================================" << std::endl;
    outputFile << "Всего уникальных слов: " << wordFrequency.size() << std::endl;
    outputFile << "\nСлово : Частота" << std::endl;
    outputFile << "-------------------" << std::endl;

    for (const auto& pair : wordFrequency) {
        outputFile << pair.first << " : " << pair.second << std::endl;
    }

    outputFile << "\nНаиболее часто встречающееся слово:" << std::endl;
    outputFile << "Слово: \"" << mostFrequentWord << "\" - " << maxFrequency << " раз(а)" << std::endl;

    outputFile.close();

    std::cout << "\nРезультаты успешно сохранены в файл: " << outputFileName << std::endl;

    return 0;
}