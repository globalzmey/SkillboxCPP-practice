#include <iostream>

int main() {
    int height, width;
    std::cout << "Введите высоту и ширину координатной системы: ";
    std::cin >> height >> width;

    if (height < 3 || width < 3) {
        std::cout << "Высота и ширина должны быть не меньше 3.\n";
        return 1;
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == height / 2 && j == width / 2) {
                std::cout << "+";
            } else if (i == height / 2) {
                if (j == width - 1) {
                    std::cout << ">";
                } else {
                    std::cout << "-";
                }
            } else if (j == width / 2) {
                if (i == 0) {
                    std::cout << "^";
                } else {
                    std::cout << "|";
                }
            } else {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}
