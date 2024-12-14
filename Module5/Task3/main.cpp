#include <iostream>

int main() {

    int day, startDayOfWeek;

    std::cout << "---<<<Майские!>>>---\n";
    std::cout << "Введите число в мае: ";
    std::cin >> day;
    std::cout << "C какого дня недели начинается месяц: ";
    std::cin >> startDayOfWeek;

    if ((day < 1 || day > 31) || (startDayOfWeek < 1 || startDayOfWeek > 7)) {
        std::cout << "Введена некорректная дата или день недели!\n";
    }
    else if ((day + startDayOfWeek - 1) % 7 == 6 || (day + startDayOfWeek - 1) % 7 == 0 || (day >= 1 && day <=5) || (day >=8 && day <= 10)) {
            std::cout << "Выходной!\n";
        }
        else {
            std::cout << "Рабочий день.\n";
        }

    return 0;

}
