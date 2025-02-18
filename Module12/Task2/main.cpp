#include <iostream>

int main() {
    float numbers[15];

    std::cout << "Ввод: ";
    for (int i = 0; i < 15; ++i) {
        std::cin >> numbers[i];
    }

    for (int i = 0; i < 14; ++i) {
        int maxIndex = i;
        for (int j = i + 1; j < 15; ++j) {
            if (numbers[j] > numbers[maxIndex]) {
                maxIndex = j;
            }
        }

        if (maxIndex != i) {
            float temp = numbers[i];
            numbers[i] = numbers[maxIndex];
            numbers[maxIndex] = temp;
        }
    }

    std::cout << "Вывод: ";
    for (int i = 0; i < 15; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}