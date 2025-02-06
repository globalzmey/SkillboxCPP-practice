#include <iostream>
#include <cmath>

int main() {
    const int SEC_IN_MINUTE = 60;
    double distance, temp, averageTime, totalTime = 0;

    std::cout << "Привет, Сэм! Сколько километров ты сегодня пробежал? ";
    std::cin >> distance;
    while (distance <= 0) {
        std::cout << "Что-то не так. Сэм, сколько километров ты сегодня пробежал?";
        std::cin >> distance;
    }

    for (int i = 1; i <= distance; i++) {
        std::cout << "Какой у тебя был темп на километре " << i << "? ";
        std::cin >> temp;
        while (temp <= 0) {
            std::cout << "Какой у тебя был темп на километре " << i << "? ";
            std::cin >> temp;
        }
        totalTime += temp;
    }

    averageTime = totalTime / distance;

    std::cout << "Вывод:\n";
    int minutes = static_cast<int>(averageTime) / SEC_IN_MINUTE;
    int seconds = static_cast<int>(std::round(averageTime)) % SEC_IN_MINUTE;

    std::cout << "Твой средний темп за тренировку: " << minutes << " минуты " << seconds << " секунд.\n";

    return 0;
}