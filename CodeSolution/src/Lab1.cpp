#include <iostream>
#include <math.h>
#include "include/Lab1.h"
using namespace std;
namespace Lab1
{
	// Вариант 7 Дана длина окружности L. Найти радиус окружности R и площадь круга S.
	void Task1()
	{
		double L;
		cout << "Введите длину окружности: ";
		cin >> L;

		const double pi = 3.14159;
		double R = L / (2 * pi);
		double S = pi * R * R;

		cout << "Радиус окружности: " << R << endl;
		cout << "Площадь круга: " << S << endl;
	}
	// Вариант 13 Дано трехзначное число. Вывести число, полученное при перестановке цифр десятков и единиц исходного числа.
	void Task2()
	{
		int number, units, tens, hundreds;

		cout << "Введите трехзначное число: ";
		cin >> number;
		hundreds = number / 100;
		units = number % 10;
		tens = (number - hundreds * 100) / 10;

		cout << "Исходное число: " << number << endl;
		cout << "Перестановка цифр десятков и единиц: " << hundreds << units << tens
			 << endl;
	}
	double f(double x)
	{
		return abs(pow(x, 4) - cos(x)) - pow((1 + (sqrt(pow(x, 6)))), 1 / 9) + pow(sin(M_PI / (pow(M_E, x) + 1)), 3);
	}
	/* Вариант 3
	Разработать программу на языке С++. Все входные и выходные данные в задачах —
	вещественные числа. Для ввода и вывода данных использовать функции scanf и printf.
	Вычислить значение выражения y = f (х) при заданном значении х
	*/
    void Task3()
    {
        double x;
        printf("Введите значение x = ");
        scanf("%lf", &x);
        printf("f(x) = %lf\n", f(x));
    }
}
