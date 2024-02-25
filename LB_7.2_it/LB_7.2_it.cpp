#include <iostream>
#include <cstdlib>
#include <ctime>

// Максимальний розмір матриці
const int MAX_SIZE = 100;

// Функція для генерації матриці
void generateMatrix(int matrix[MAX_SIZE][MAX_SIZE], int k, int n) {
    std::srand(std::time(0));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = std::rand() % 100 + 1;
        }
    }
}

// Функція для виведення матриці
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int k, int n) {
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

// Функція для знаходження суми максимальних елементів у парних рядках
int sumMaxInEvenRows(int matrix[MAX_SIZE][MAX_SIZE], int k, int n) {
    int sum = 0;
    for (int i = 0; i < k; i += 2) { // Проходимо тільки по парних рядках
        int maxElem = matrix[i][0];
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] > maxElem) {
                maxElem = matrix[i][j];
            }
        }
        sum += maxElem;
    }
    return sum;
}

int main() {
    int k, n;
    std::cout << "Rozmir (k n): ";
    std::cin >> k >> n;

    int matrix[MAX_SIZE][MAX_SIZE];
    generateMatrix(matrix, k, n);

    std::cout << "Matrix:\n";
    printMatrix(matrix, k, n);

    int sum = sumMaxInEvenRows(matrix, k, n);
    std::cout << "Sum: " << sum << "\n";

    return 0;
}