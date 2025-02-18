#include <iostream>

int main() {
    int numbers[15] = {75, 76, 77, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88};

    int minElement = numbers[0];
    for (int i = 1; i < 15; ++i) {
        if (numbers[i] < minElement) {
            minElement = numbers[i];
        }
    }

    int expectedSum = 14 * minElement + 91;

    int arraySum = 0;
    for (int i = 0; i < 15; ++i) {
        arraySum += numbers[i];
    }

    int duplicate = arraySum - expectedSum;

    std::cout << "Повторяющееся число: " << duplicate << std::endl;

    return 0;
}