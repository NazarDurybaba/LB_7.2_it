#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../LB_7.2_it.cpp"


TEST_CLASS(MatrixTests)
{
public:
    // Тест для перевірки генерації матриці
    TEST_METHOD(TestMatrixGeneration)
    {
        const int k = 3;
        const int n = 4;
        int matrix[MAX_SIZE][MAX_SIZE];
        generateMatrix(matrix, k, n);

    
        bool nonZeroFound = false;
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] != 0) {
                    nonZeroFound = true;
                    break;
                }
            }
            if (nonZeroFound)
                break;
        }

        Assert::IsTrue(nonZeroFound);
    }

    // Тест для перевірки обчислення суми максимальних елементів у парних рядках
    TEST_METHOD(TestSumMaxInEvenRows)
    {
        const int k = 4;
        const int n = 4;
        int matrix[MAX_SIZE][MAX_SIZE];
        generateMatrix(matrix, k, n); 
        
        int expectedSum = 0;
        for (int i = 0; i < k; i += 2) {
            int maxElem = matrix[i][0];
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] > maxElem) {
                    maxElem = matrix[i][j];
                }
            }
            expectedSum += maxElem;
        }

        
        Assert::AreEqual(expectedSum, sumMaxInEvenRows(matrix, k, n));
    }
};
