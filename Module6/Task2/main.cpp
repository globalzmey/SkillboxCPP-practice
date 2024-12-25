#include <iostream>

int main() {

    int count = 0;
    long long number;
    std::cout << "Введите число: ";
    std::cin >> number;

    while (number != 0) {
        ++count;
        number /= 10;
    }
    std::cout << "Цифр в числе:  " << count << "\n";

    return 0;
}

