#include <iostream>
#include <string>
#include "include/Lab1.h" // Подключаем хедеры для всех лабораторных работ
#include "include/Lab2.h"
#include "include/Lab3.h"
#include "include/Lab4.h"
#include "include/Lab5.h"
#include <cstdlib>

void SetConsoleToUnicode()
{
#ifdef _WIN32
    system("chcp 65001");  // Устанавливаем кодовую страницу UTF-8
#endif
}
using namespace std;

int main() {
    SetConsoleToUnicode();
    int labNumber, taskNumber;
    string input;

    while (true) {
        cout << "Введите номер лабораторной работы (1-5) или 'q' для выхода: ";
        cin >> input;

        if (input == "q") {
            break;
        }

        try {
            labNumber = stoi(input);

            cout << "Введите номер задания (1-3): ";
            cin >> taskNumber;

            switch (labNumber) {
                case 1:
                    switch (taskNumber) {
                        case 1:
                            Lab1::Task1();
                            break;
                        case 2:
                            Lab1::Task2();
                            break;
                        case 3:
                            Lab1::Task3();
                            break;
                        default:
                            cout << "Неверный номер задания для лабораторной работы 1." << endl;
                            break;
                    }
                    break;

                case 2:
                    switch (taskNumber) {
                        case 1:
                            Lab2::Task1();
                            break;
                        case 2:
                            Lab2::Task2();
                            break;
                        case 3:
                            Lab2::Task3();
                            break;
                        default:
                            cout << "Неверный номер задания для лабораторной работы 2." << endl;
                            break;
                    }
                    break;

                case 3:
                    switch (taskNumber) {
                        case 1:
                            Lab3::Task1();
                            break;
                        case 2:
                            Lab3::Task2();
                            break;
                        case 3:
                            Lab3::Task3();
                            break;
                        default:
                            cout << "Неверный номер задания для лабораторной работы 3." << endl;
                            break;
                    }
                    break;

                case 4:
                    switch (taskNumber) {
                        case 1:
                            Lab4::Task1();
                            break;
                        case 2:
                            Lab4::Task2();
                            break;
                        case 3:
                            Lab4::Task3();
                            break;
                        default:
                            cout << "Неверный номер задания для лабораторной работы 4." << endl;
                            break;
                    }
                    break;

                case 5:
                    switch (taskNumber) {
                        case 1:
                            Lab5::Task1();
                            break;
                        case 2:
                            Lab5::Task2();
                            break;
                        case 3:
                            Lab5::Task3();
                            break;
                        default:
                            cout << "Неверный номер задания для лабораторной работы 5." << endl;
                            break;
                    }
                    break;

                default:
                    cout << "Неверный номер лабораторной работы." << endl;
                    break;
            }
        }
        catch (const std::exception &e) {
            cout << "Неверный ввод. Попробуйте снова." << endl;
        }

        cout << endl;
        return 0;
    }
}
