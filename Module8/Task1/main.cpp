#include <iostream>
#include <cmath>

int main() {
    float F, m;
    int t;

    std::cout << "Введите тягу двигателя в ньютонах: ";
    std::cin >> F;
    while (F < 0) {
        std::cout << "Введите корректное значение тяги: ";
        std::cin >> F;
    }

    std::cout << "Введите время работы двигателя в секундах: ";
    std::cin >> t;
    while (F < 0) {
        std::cout << "Введите корректное значение времени в секундах: ";
        std::cin >> t;
    }

    std::cout << "Введите массу звездолёта в килограммах: ";
    std::cin >> m;
    while (F < 0) {
        std::cout << "Введите корректное значение массы звездолёта: ";
        std::cin >> m;
    }

    std::cout << "Звездолёт пролетит: " << ((F / m) * pow(t, 2)) / 2 << " метров за " << t << " секунд.\n";

    return 0;
}
