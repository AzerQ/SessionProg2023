#include <iostream>
using namespace std;
#include "include/Lab3.h"
namespace Lab3
{
    // Вариант 8
    void Task1()
    {
        cout << endl
             << endl
             << "Task 1" << endl;
        cout << "FOR" << endl;
        for (int i = 1; i <= 19; i += 2)
        {
            cout << i << " в квадрате: " << i * i << endl;
        }

        cout << "WHILE" << endl;
        int i = 1;
        while (i <= 19)
        {
            cout << i << " в квадрате: " << i * i << endl;
            i += 2;
        }

        cout << "DO WHILE" << endl;
        i = 1;
        do
        {
            cout << i << " в квадрате: " << i * i << endl;
            i += 2;
        } while (i <= 19);
    }
    // Вариант 2
    void Task2()
    {
        int N;
        cout << "Введите целое положительное число: ";
        cin >> N;

        if(N < 2) {
            std::cout << "Произведение чётных чисел не превышающих данное число равно 0.\n";
            return;
        }
        long long product = 1;
        for (int i = 2; i <= N; i += 2) {
            product *= i;
        }
        cout << "Произведение чётных чисел не превышающих данное число равно " << product << ".\n";
    }
    // Вариант 9
    void Task3()
    {
        cout << endl
             << endl
             << "Task 3" << endl;
        int positiveCount = 0, negativeCount = 0, num;
        do
        {
            cout << "Введите число (для завершения введите 0): ";
            cin >> num;
            if (num > 0)
            {
                positiveCount++;
            }
            else if (num < 0)
            {
                negativeCount++;
            }
        } while (num != 0);
        int totalCount = positiveCount + negativeCount;
        float positivePercentage = (float)positiveCount / totalCount * 100;
        float negativePercentage = (float)negativeCount / totalCount * 100;
        cout << "Процент положительных чисел: " << positivePercentage << "%" << endl;
        cout << "Процент отрицательных чисел: " << negativePercentage << "%" << endl;
    }

}
