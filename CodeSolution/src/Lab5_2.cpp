#include <iostream>
#include <vector>
#include <cmath>
#include "include/Lab5_2.h"

namespace Lab5_2{
    std::vector<std::vector<double>> matrixMult(std::vector<std::vector<double>>& a, std::vector<std::vector<double>>& b) {
        std::vector<std::vector<double>> result(a.size(), std::vector<double>(b[0].size()));
        for (size_t i = 0; i < a.size(); i++) {
            for (size_t j = 0; j < b[0].size(); j++) {
                for (size_t k = 0; k < b.size(); k++) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return result;
    }

    void Task1()
    {
        int n, m;
        std::cout << "Введите количество строк и столбцов матрицы B: ";
        std::cin >> n >> m;
        std::vector<std::vector<double>> B = InputMatrix(n, m);

        std::cout << "Введите количество строк и столбцов матрицы C: ";
        std::cin >> n >> m;
        std::vector<std::vector<double>> C = InputMatrix(n, m);

        // your logic for Task1
        double product = 1;
        double sumPositive = 0;
        double min1 = B[0][0], min2 = B[0][0];
        for (int i = 0; i < B.size(); i++) {
            for (int j = 0; j < B[i].size(); j++) {
                product *= B[i][j];
                if (B[i][j] > 0) sumPositive += B[i][j];
                if (i == 0 || i == B.size() - 1 || j == 0 || j == B[i].size() - 1) {
                    if (B[i][j] < min1) {
                        min2 = min1;
                        min1 = B[i][j];
                    } else if (B[i][j] < min2) {
                        min2 = B[i][j];
                    }
                }
            }
        }

        std::vector<std::vector<double>> A = matrixMult(B, C);
        for (auto &row : A) {
            for (auto &el : row) {
                el *= 3;
            }
        }

        std::cout << "Произведение элементов: " << product << std::endl;
        std::cout << "Сумма положительных элементов: " << sumPositive << std::endl;
        std::cout << "Два наименьших значения на периметре: " << min1 << ", " << min2 << std::endl;
        std::cout << "Матрица A = 3·B·C: " << std::endl;
        for (const auto &row : A) {
            for (const auto &el : row) {
                std::cout << el << ' ';
            }
            std::cout << '\n';
        }
    }

    void Task2()
    {
        int n, m;
        std::cout << "Введите количество строк и столбцов матрицы C: ";
        std::cin >> n >> m;
        std::vector<std::vector<double>> C = InputMatrix(n, m);

        // your logic for Task2
        std::vector<double> D(C.size());
        std::vector<int> G;
        for (int i = 0; i < C.size(); i++) {
            double sumPositive = 0;
            int countPositive = 0;
            for (int j = 0; j < C[i].size(); j++) {
                if (C[i][j] > 0) {
                    sumPositive += C[i][j];
                    countPositive++;
                }
            }
            D[i] = countPositive > 0 ? sumPositive / countPositive : 0;
        }
        for (int j = 0; j < C[0].size(); j++) {
            bool alternatingSigns = true;
            for (int i = 1; i < C.size() && alternatingSigns; i++) {
                if (std::signbit(C[i][j]) == std::signbit(C[i - 1][j])) {
                    alternatingSigns = false;
                }
            }
            if (alternatingSigns) {
                G.push_back(j);
            }
        }
        std::cout << "Вектор D: ";
        for (double el : D) {
            std::cout << el << " ";
        }
        std::cout << std::endl;

        std::cout << "Вектор G: ";
        for (int col : G) {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }
    std::vector<std::vector<double>> InputMatrix(int n, int m) {
        std::vector<std::vector<double>> matrix(n, std::vector<double>(m));
        std::cout << "Введите элементы матрицы " << n << "x" << m << ":\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cin >> matrix[i][j];
            }
        }
        return matrix;
    }
}
