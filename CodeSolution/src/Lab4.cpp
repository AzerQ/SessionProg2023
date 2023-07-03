#include <iostream>
#include <math.h>
#include "include/Lab4.h"
using namespace std;
namespace Lab4
{
    int get_sum_divisors(int num)
    {
        int sum = 0;
        for (int i = 1; i < num; i++)
        {
            if (num % i == 0)
            {
                sum += i;
            }
        }
        return sum;
    }

    // функция f(x)
    double f(double x)
    {
        return x * log(x) - 1;
    }

    // производная функции f(x)
    double df(double x)
    {
        return log(x) + 1;
    }

    // метод хорд
    double chord_method(double a, double b)
    {
        double fa = f(a), fb = f(b), x = a;
        int iteration = 0;
        while (abs(f(x)) > 1e-4)
        {
            x = (a * fb - b * fa) / (fb - fa);
            if (f(x) * fa > 0)
            {
                fa = f(x);
                a = x;
            }
            else
            {
                fb = f(x);
                b = x;
            }
            iteration++;
        }
        cout << "Метод хорд: ";
        cout << "Корень = " << x << ", достигнут за " << iteration << " итераций" << endl;
        return x;
    }

    // метод касательных
    double tangent_method(double a, double b)
    {
        double x = a;
        int iteration = 0;
        while (abs(f(x)) > 1e-4)
        {
            x = x - f(x) / df(x);
            iteration++;
        }
        cout << "Метод касательных: ";
        cout << "Корень = " << x << ", достигнут за " << iteration << " итераций" << endl;
        return x;
    }

    // Вариант 8
    void Task1()
    {
        cout << endl
             << endl
             << "Task 1" << endl;
        cout << "FOR" << endl;
        int n;
        cout << "Введите количество элементов: ";
        cin >> n;

        int sequence[n];
        cout << "Введите последовательность чисел:" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> sequence[i];
        }

        for (int i = 0; i < n - 1; i++)
        {
            int sum1 = get_sum_divisors(sequence[i]);
            int sum2 = get_sum_divisors(sequence[i + 1]);
            if (sum1 == sequence[i + 1] && sum2 == sequence[i])
            {
                cout << "Найдена пара дружественных чисел: " << sequence[i] << " и " << sequence[i + 1] << endl;
            }
        }

        cout << "Пара дружественных чисел не найдена." << endl;
    }
    // Функция перевода числа из системы с основанием 3 в систему с основанием 7
    int base3_to_base7(int num)
    {
        int answer = 0;
        int power3 = 1;
        while (num > 0)
        {
            answer += (num % 7) * power3;
            num /= 7;
            power3 *= 3;
        }
        return answer;
    }

    // Функция для вычисления значения C
    int calculate_c(int a, int b)
    {
        int a_in_base7 = base3_to_base7(a);
        return 2 * (pow(a_in_base7, 2) + pow(b, 2));
    }
    // Вариант 2
    void Task2()
    {
        int a, b;
        cout << "Число a в 3-ной системе: ";
        cin >> a;
        cout << "Число b в 7-ной системе: ";
        cin >> b;
        int c = calculate_c(a, b);
        cout << "C in decimal system: " << c << endl;

        // Перевод числа c в систему с основанием 4
        int c_in_base4 = 0;
        int power4 = 1;
        while (c > 0)
        {
            c_in_base4 += (c % 4) * power4;
            c /= 4;
            power4 *= 10;
        }

        cout << "C in base 4: " << c_in_base4 << endl;
    }
    // Вариант 9
    void Task3()
    {
        cout << endl
             << endl
             << "Task 3" << endl;
        double a, b;
        cout << "Введите начало и конец интервала: ";
        cin >> a >> b;
        /*while (f(a) * f(b) > 0)
        {
            cout << "Неверно задан интервал, повторите ввод: ";
            cin >> a >> b;
        }*/
        double hordRes = chord_method(a, b);
        double tangetRes = tangent_method(a, b);
        cout << "Hord result = " << hordRes << endl;
        cout << "Tangent result = " << tangetRes << endl;
    }
}
