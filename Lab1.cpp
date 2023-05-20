#include <iostream>
#include <math.h>
using namespace std;

// Вариант 7
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
// Вариант 13
void Task2()
{
    int number, units, tens, hundreds;

    cout << "Введите трехзначное число: ";
    cin >> number;
    hundreds = number / 100;
    units = number % 10;
    tens = (number - hundreds * 100) / 10;

    cout << "Исходное число: " << number << endl;
    cout << "Перестановка цифр десятков и единиц: " << hundreds << units << tens << endl;
}
double f(double x)
{
    return abs(pow(x, 4) - cos(x)) - 
    pow((1 + (sqrt(pow(x, 6)))), 1 / 9) + 
    pow(sin(M_PI / (pow(M_E, x) + 1)), 3);
}
// Вариант 3
void Task3()
{
    double x;
    cout << "Введите значение x = ";
    cin >> x;
    cout << "f(x) = " << f(x) << endl;
}
int main(int argc, char const *argv[])
{
    Task1();
    Task2();
    Task3();
    return 0;
}
