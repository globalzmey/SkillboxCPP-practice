#include <iostream>

int main() {
    int total_length, exclam_count;

    std::cout << "Введите общую длину колонтитула: ";
    std::cin >> total_length;

    if (total_length < 3) {
        std::cout << "Ошибка: общая длина колонтитула должна быть не менее 3.\n";
        return 1;
    }

    std::cout << "Введите количество восклицательных знаков: ";
    std::cin >> exclam_count;

    if (exclam_count < 0 || exclam_count > total_length) {
        std::cout << "Ошибка: количество восклицательных знаков должно быть неотрицательным и не превышать длину колонтитула.\n";
        return 1;
    }

    int tildes_left = (total_length - exclam_count) / 2;
    int tildes_right = total_length - exclam_count - tildes_left;

    for (int i = 0; i < tildes_left; i++) {
        std::cout << "~";
    }
    for (int i = 0; i < exclam_count; i++) {
        std::cout << "!";
    }
    for (int i = 0; i < tildes_right; i++) {
        std::cout << "~";
    }

    std::cout << "\n";

    return 0;
}
