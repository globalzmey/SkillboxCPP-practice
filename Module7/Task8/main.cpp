#include <iostream>

int main() {
    int height;

    std::cout << "Введите высоту елочки: ";
    std::cin >> height;

    while (height <= 0) {
        std::cout << "Ошибка: высота должна быть положительной. Введите снова: ";
        std::cin >> height;
    }

    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= height - i; ++j) {
            std::cout << " ";
        }
        for (int j = 1; j <= (2 * i - 1); ++j) {
            std::cout << "#";
        }
        std::cout << "\n";
    }

    return 0;
}
