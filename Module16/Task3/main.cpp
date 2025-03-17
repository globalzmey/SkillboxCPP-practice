#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::cout << "Введите выражение в формате <число-1><действие><число-2> (например, 3.5+2.1): ";
    std::string buffer;
    std::cin >> buffer;

    std::stringstream buffer_stream(buffer);

    double a, b;
    char operation;

    buffer_stream >> a >> operation >> b;

    double result = 0.0;
    bool valid_operation = true;

    switch (operation) {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        if (b != 0.0) {
            result = a / b;
        } else {
            std::cout << "Ошибка: деление на ноль!" << std::endl;
            valid_operation = false;
        }
        break;
    default:
        std::cout << "Ошибка: неизвестная операция!" << std::endl;
        valid_operation = false;
        break;
    }

    if (valid_operation) {
        std::cout << "Результат: " << result << std::endl;
    }

    return 0;
}