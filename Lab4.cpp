#include <iostream>
#include <math.h>
using namespace std;

int get_sum_divisors(int num) {
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum;
}

// функция f(x)
double f(double x) {
    return x * log(x) - 1;
}

// производная функции f(x)
double df(double x) {
    return log(x) + 1;
}

// метод хорд
double chord_method(double a, double b) {
    double fa = f(a), fb = f(b), x = a;
    int iteration = 0;
    while (abs(f(x)) > 1e-4) {
        x = (a * fb - b * fa) / (fb - fa);
        if (f(x) * fa > 0) {
            fa = f(x);
            a = x;
        } else {
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
double tangent_method(double a, double b) {
    double x = a;
    int iteration = 0;
    while (abs(f(x)) > 1e-4) {
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
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int sum1 = get_sum_divisors(sequence[i]);
        int sum2 = get_sum_divisors(sequence[i + 1]);
        if (sum1 == sequence[i + 1] && sum2 == sequence[i]) {
            cout << "Найдена пара дружественных чисел: " << sequence[i] << " и " << sequence[i + 1] << endl;
        }
    }

    cout << "Пара дружественных чисел не найдена." << endl;
}
// Вариант 2
void Task2()
{
     int p = 3, q = 7, r = 4, A, B, C, result;
    cout<<"Введите значение A: ";
    cin>>A;
    cout<<"Введите значение B: ";
    cin>>B;

    C = 2 * (A*A + B*B);
    int c_in_decimal = 0, temp = 0, i = 0;
    while(C!=0)
    {
        temp = C%10;
        c_in_decimal += temp * pow(p,i);
        i++;
        C/=10;
    }

    result = 0, i = 0;
    while(c_in_decimal != 0)
    {
        temp = c_in_decimal % r;
        result += temp * pow(10,i);
        c_in_decimal /= r;
        i++;
    }

    cout<<"C в 10-ой системе счисления: "<<c_in_decimal<<endl;
    cout<<"C в "<<r<<"-ой системе счисления: "<<result<<endl;
    
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
    while (f(a) * f(b) > 0) {
        cout << "Неверно задан интервал, повторите ввод: ";
        cin >> a >> b;
    }
    double hordRes = chord_method(a, b);
    double tangetRes = tangent_method(a, b);
    cout << "Hord result = " << hordRes << endl;
    cout << "Tangent result = " << tangetRes << endl;
}

int main(int argc, char const *argv[])
{
    Task1();
    Task2();
    Task3();
    /* code */
    return 0;
}
