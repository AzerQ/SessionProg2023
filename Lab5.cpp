#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
namespace Lab5 {
// Вариант 12
void Task1()
{
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    double x[n];
    int countNegative = 0;
    double sumFirstLastPositive = 0;
    double min = x[0];
    int minIndex = 0;

    cout << "Введите элементы массива:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> x[i];

        if (x[i] < 0)
        {
            countNegative++;
        }
        else if (x[i] > 0)
        {
            sumFirstLastPositive += x[i];
            if (i == 0 || i == n - 1)
            {
                sumFirstLastPositive += x[i];
            }
        }

        if (x[i] < min)
        {
            min = x[i];
            minIndex = i;
        }
    }

    double percentNegative = countNegative * 100.0 / n;

    cout << "Процент отрицательных чисел в массиве: " << percentNegative << "%" << endl;
    cout << "Сумма первого и последнего положительных элементов: " << sumFirstLastPositive << endl;

    for (int i = n - 1; i >= 0; i--)
    {
        cout << x[i] << " ";
    }

    cout << endl;

    if (minIndex == n - 1)
    {
        // Минимальный элемент уже был последним
        x[minIndex] = 0;
    }
    else
    {
        // Переставляем минимальный элемент в конец массива
        for (int i = minIndex; i < n - 1; i++)
        {
            x[i] = x[i + 1];
        }
        x[n - 1] = min;
    }

    cout << "Массив после удаления минимального элемента:";
    for (int i = 0; i < n - 1; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}
 
string DecToOct(int x)
{
        string s1="";
        int t=0;
        while (x>=1)
        {
                t=x%8;
                x=(x-t)/8;
                s1+=std::to_string(t).c_str();
        }
        reverse(s1.begin(),s1.end());
        return s1;
}

void PrintArray(int arr[], int n, bool useOct)
{
    for (int i = 0; i < n; i++)
    {
        if (useOct)
        {
            cout << DecToOct(arr[i]) << " ";
        }
        else
        {
            cout << arr[i] << " ";
        }
    }
}

void MaxNumbers(int mass[], int size)
{

    /* Отсортируем массив по убыванию */
    for (int i = 1; i < size; ++i)
    {
        for (int j = 0; j < size - i; j++)
        {
            if (mass[j] < mass[j + 1])
            {
                // Обмен местами
                int temp = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = temp;
            }
        }
    }
    int Z[6];
    int oddCount = 0;
    for (int i = 0; i < 6; i++)
    {
        Z[i] = mass[i];
        if (Z[i] % 2 == 0)
        {
            oddCount++;
        }
    }
    cout << "Массив 6 максимальных элементов: " << endl;
    PrintArray(Z, 6, false);
    int oddZ[oddCount];
    int oddIterator = 0;
    for (int i = 0; i < 6; i++)
    {
        if (Z[i] % 2 == 0)
        {
            oddZ[oddIterator++] = Z[i];
        }
    }
    cout << endl << "Массив 6 максимальных элементов (только нечётные 8-ная система): " << endl;
    PrintArray(oddZ, oddCount, true);
}
// Вариант 5
void Task2()
{
    int n = 0;
    cout << "Размер массива: ";
    cin >> n;
    int arr[n];
    cout <<  "Введите массив: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    MaxNumbers(arr, n);
}
void findShortestDecreasingEvenSequence(std::vector<int> arr) {
    int start_idx = -1, end_idx = -1, current_seq_len = 0, min_seq_len = arr.size() + 1;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 0) { // если встретилось четное число
            if (current_seq_len == 0) { // начинаем новую последовательность
                start_idx = i;
                current_seq_len = 1;
            }
            else if (arr[i] < arr[i-1]) { // продолжаем убывающую последовательность
                current_seq_len++;
            }
            else { // обнаружили неубывающее число, заканчиваем последовательность
                current_seq_len = 0;
            }
            if (current_seq_len > 0 && i == arr.size() - 1) { // последовательность заканчивается в конце массива
                end_idx = i;
                if (current_seq_len < min_seq_len) {
                    min_seq_len = current_seq_len;
                }
                break;
            }
        }
        else { // обнаружили нечетное число, заканчиваем последовательность
            if (current_seq_len > 0) {
                end_idx = i - 1;
                if (current_seq_len < min_seq_len) {
                    min_seq_len = current_seq_len;
                }
                current_seq_len = 0;
            }
        }
    }

    // выводим результаты
    if (min_seq_len == arr.size() + 1) { // не нашли ни одной последовательности
        std::cout << "Нет такой последователльности" << std::endl;
    }
    else {
        std::cout << "Минимальная последователность убывающих чётных чисел: " << std::endl;
        for (int i = start_idx; i <= end_idx; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
}

// Вариант 8
void Task3()
{
    int size = 0;
    std::vector<int> arr;
    cout << endl << "Введите размер массива: ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        int elem;
        cin >> elem;
        arr.push_back(elem);
    }
    findShortestDecreasingEvenSequence(arr);
}

int main(int argc, char const *argv[])
{
    Task1();
    Task2();
    Task3();
    /* code */
    return 0;
}
}
