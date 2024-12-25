#include <iostream>

int main() {
    std::cout << "Введите, который час: ";
    int hours;
    std::cin >> hours;
    if (hours >= 0 && hours < 13) {
        if (hours == 0) {
            hours = 12;
        }
        while (hours > 0) {
        std::cout << "Ку-Ку!\n";
        hours--;
        }
    } else {
        std::cout << "Введено некорректное время!\n";
    }
    return 0;
}

