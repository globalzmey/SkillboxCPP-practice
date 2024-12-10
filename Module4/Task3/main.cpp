#include <iostream>

int main() {

    std::cout << "Введите число: ";
    int someNumber;
    std::cin >> someNumber;
    if (someNumber % 2) {
        std::cout << "Число " << someNumber << " нечётное" << "\n";
    }
    else {
        std::cout << "Число " << someNumber << " чётное" << "\n";
    }

    return 0;
}
