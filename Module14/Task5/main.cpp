#include <iostream>
#include <vector>

const int SIZE = 12;

void initializeBubbleWrap(std::vector<std::vector<bool>>& bubbleWrap) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            bubbleWrap[i][j] = true;
        }
    }
}

void displayBubbleWrap(const std::vector<std::vector<bool>>& bubbleWrap) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << (bubbleWrap[i][j] ? 'o' : 'x') << " ";
        }
        std::cout << std::endl;
    }
}

void popBubbles(std::vector<std::vector<bool>>& bubbleWrap, int startRow, int startCol, int endRow, int endCol) {
    if (startRow < 0 || startRow >= SIZE || endRow < 0 || endRow >= SIZE ||
        startCol < 0 || startCol >= SIZE || endCol < 0 || endCol >= SIZE ||
        startRow > endRow || startCol > endCol) {
        std::cout << "Ошибка: неверные координаты региона." << std::endl;
        return;
    }

    for (int i = startRow; i <= endRow; ++i) {
        for (int j = startCol; j <= endCol; ++j) {
            if (bubbleWrap[i][j]) {
                bubbleWrap[i][j] = false;
                std::cout << "Pop!" << std::endl;
            }
        }
    }
}

bool areBubblesLeft(const std::vector<std::vector<bool>>& bubbleWrap) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (bubbleWrap[i][j]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::vector<std::vector<bool>> bubbleWrap(SIZE, std::vector<bool>(SIZE));

    initializeBubbleWrap(bubbleWrap);

    while (areBubblesLeft(bubbleWrap)) {
        displayBubbleWrap(bubbleWrap);

        int startRow, startCol, endRow, endCol;
        std::cout << "Введите координаты начала региона (строка столбец): ";
        std::cin >> startRow >> startCol;
        std::cout << "Введите координаты конца региона (строка столбец): ";
        std::cin >> endRow >> endCol;

        popBubbles(bubbleWrap, startRow, startCol, endRow, endCol);
    }

    std::cout << "Все пузырьки лопнуты. Программа завершена." << std::endl;

    return 0;
}