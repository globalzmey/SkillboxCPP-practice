#include <iostream>

const int SIZE = 5;

int main() {
    int array[SIZE][SIZE];
    int number = 0;

    for (int i = 0; i < SIZE; ++i) {
        int direction = (i % 2 == 0) ? 1 : -1;

        int startCol = (direction == 1) ? 0 : SIZE - 1;

        for (int j = 0; j < SIZE; ++j) {
            int col = startCol + j * direction;
            array[i][col] = number++;
        }
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}