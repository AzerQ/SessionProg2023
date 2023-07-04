#include "Lab6.h"
#include <iostream>
#include <fstream>
#include <sstream>

namespace Lab6 {
    void Task1() {
        std::string filename;
        std::cout<<"Введите имя файла: ";
        std::cin>> filename;
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cout << "Ошибка открытия файла.\n";
            return;
        }
        std::cout<<"Содержимое файла: "<<std::endl;
        std::string line;
        int pointCount = 0;
        while (std::getline(file, line)) {
            std::cout<<line<<std::endl;
            for (char c : line) {
                if (c == '.') {
                    pointCount++;
                }
            }
        }

        std::cout << std::endl<< "Количество точек в тексте: " << pointCount << std::endl;
        file.close();
    }

    void Task2() {
        std::string filename;
        std::cout<<"Введите имя файла: ";
        std::cin>> filename;
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cout << "Ошибка открытия файла.\n";
            return;
        }
        std::cout<<"Содержимое файла: "<<std::endl;
        std::string line;
        int lineCount = 0;
        bool hasExclamation = false;
        while (std::getline(file, line)) {
            std::cout<<line<<std::endl;
            lineCount++;
            if (line.find('!') != std::string::npos) {
                hasExclamation = true;
                break;
            }
        }
        std::cout<<std::endl;
        if (hasExclamation) {
            std::cout << "Текст содержит восклицательный знак. Обнаружен на строке: " << lineCount << std::endl;
        } else {
            std::cout << "Текст не содержит восклицательных знаков.\n";
        }
        file.close();
    }

    void Task3() {
        std::string filename;
        std::cout<<"Введите имя файла: ";
        std::cin>> filename;
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cout << "Ошибка открытия файла.\n";
            return;
        }
        std::cout<<"Содержимое файла: "<<std::endl;
        std::string line;
        int wordCount = 0;
        int lineCount = 0;
        while (std::getline(file, line)) {
            std::cout<<line<<std::endl;
            lineCount++;
            if (lineCount % 2 != 0) {
                std::istringstream iss(line);
                std::string word;
                while (iss >> word) {
                    wordCount++;
                }
            }
        }

        std::cout << std::endl << "Количество слов в нечётных строках текста: " << wordCount << std::endl;
        file.close();
    }
}
