#include <iostream>

int main() {

    std::cout << "Введите первое число: ";
    int firstNumber;
    std::cin >> firstNumber;
    std::cout << "Введите второе число: ";
    int secondNumber;
    std::cin >> secondNumber;
    std::cout << "-----Проверяем-----\n";
    if (firstNumber % secondNumber) {
        std::cout << "Нет, " << firstNumber <<" не делится на " << secondNumber << " без остатка!\n";
    }
    else {
        std::cout << "Да, " << firstNumber <<" делится на " << secondNumber << " без остатка!\n";
    }

    return 0;
}
