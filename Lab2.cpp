#include <iostream>
using namespace std;

// Вариант 9
void Task1()

{
    cout << endl << endl
         << "Task 1" << endl ;
    int a = 0;
    cout << "Enter a = ";
    cin >> a;

    if (a < -3)
    {
        cout << "f(a) = 3";
    }

    else
    {
        cout << "f(a) = 4";
    }
}
// Вариант 2
void Task2()
{
    cout << endl << endl
         << "Task 2" << endl;
    int x = 0, y = 0;
    cout << "Enter x = ";
    cin >> x;
    cout << "Enter y = ";
    cin >> y;
    if (((y <= 3) && (y >= -3)) && ((x >= -3) && (x <= 3)))
    {
        cout << "Point entered in area";
    }
    else
    {
        cout << "Not in area!";
    }
}
// Вариант 9
void Task3()
{
    cout << endl << endl
         << "Task 3" << endl;
    float a, b;
    cout << "Enter a = ";
    cin >> a;
    cout << "Enter b = ";
    cin >> b;
    if (a == 0)
    {
        cout << "Line is not crossing the x-axis.\n";
        return;
    }
    float intersection = -b / a;
    cout << "Line intersects the x-axis at point (" << intersection << ", 0).\n";
}

int main(int argc, char const *argv[])
{
    Task1();
    Task2();
    Task3();
    /* code */
    return 0;
}

