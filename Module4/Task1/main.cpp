#include <iostream>

int main() {

    std::cout << "Введите первое число: ";
    int firstNumber;
    std::cin >> firstNumber;
    std::cout << "Введите второе число: ";
    int secondNumber;
    std::cin >> secondNumber;

    std::cout << "-----Проверяем-----\n";

    if (firstNumber > secondNumber) {
        std::cout << "Наименьшее число: " << secondNumber << "\n";
    }
    else if (firstNumber < secondNumber) {
        std::cout << "Наименьшее число: " << firstNumber << "\n";
    }
    else {
        std::cout << "Числа равны!\n";
    }

    return 0;
}
