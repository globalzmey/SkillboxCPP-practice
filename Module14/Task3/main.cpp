#include <iostream>

const int SIZE = 4;

bool areMatricesEqual(int A[SIZE][SIZE], int B[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (A[i][j] != B[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void convertToDiagonal(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (i != j) {
                matrix[i][j] = 0;
            }
        }
    }
}

void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int A[SIZE][SIZE];
    int B[SIZE][SIZE];

    std::cout << "Введите элементы матрицы A (4x4):" << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cin >> A[i][j];
        }
    }

    std::cout << "Введите элементы матрицы B (4x4):" << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cin >> B[i][j];
        }
    }

    if (areMatricesEqual(A, B)) {
        std::cout << "Матрицы равны." << std::endl;

        convertToDiagonal(A);

        std::cout << "Диагональная матрица:" << std::endl;
        printMatrix(A);
    } else {
        std::cout << "Матрицы не равны." << std::endl;
    }

    return 0;
}