#include <iostream>

int main() {

    std::cout << "Введите число очков опыта: ";
    int experience;
    std::cin >> experience;
    std::cout << "-----Считаем-----\n";

    if (experience >= 5000) {
        std::cout << "Ваш уровень: Бог!\n";
    }
    else if (experience >= 2500) {
        std::cout << "Ваш уровень: 3\n";
    }
    else if (experience >= 1000) {
        std::cout << "Ваш уровень: 2\n";
    }
        else {
            std::cout << "Ваш уровень: 1\n";
    }

    return 0;
}
