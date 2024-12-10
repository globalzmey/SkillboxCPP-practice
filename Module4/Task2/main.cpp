#include <iostream>

int main() {

    std::cout << "Введите первое число: ";
    int firstNumber;
    std::cin >> firstNumber;
    std::cout << "Введите второе число: ";
    int secondNumber;
    std::cin >> secondNumber;
    std::cout << "Введите их сумму: ";
    int sumNumbers;
    std::cin >> sumNumbers;

    std::cout << "-----Проверяем-----\n";

    if (sumNumbers == (firstNumber + secondNumber)) {
        std::cout << "Верно!\n";
    }
    else {
        std::cout << "Ошибка! Верный результат: " << firstNumber + secondNumber << "\n";
    }

    return 0;
}
