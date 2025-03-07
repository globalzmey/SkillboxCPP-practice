#include <iostream>

const int SIZE = 5;
const int MAX_HEIGHT = 10;

int main() {
    bool world[SIZE][SIZE][MAX_HEIGHT] = {false};

    std::cout << "Введите высоты блоков для ландшафта 5x5 (от 0 до 10):" << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            int height;
            std::cin >> height;

            if (height < 0 || height > MAX_HEIGHT) {
                std::cout << "Ошибка: высота должна быть от 0 до 10." << std::endl;
                return 1;
            }

            for (int level = 0; level < height; ++level) {
                world[i][j][level] = true;
            }
        }
    }

    int sliceLevel;
    std::cout << "Введите уровень среза (от 0 до 9): ";
    std::cin >> sliceLevel;

    if (sliceLevel < 0 || sliceLevel >= MAX_HEIGHT) {
        std::cout << "Ошибка: уровень среза должен быть от 0 до 9." << std::endl;
        return 1;
    }

    std::cout << "Горизонтальный срез на уровне " << sliceLevel << ":" << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << (world[i][j][sliceLevel] ? "1 " : "0 ");
        }
        std::cout << std::endl;
    }

    return 0;
}