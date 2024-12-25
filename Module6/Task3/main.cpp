#include <iostream>

int main() {
    std::string debtorName;
    int totalDebt, payment;

    std::cout << "Введите имя должника: ";
    std::getline(std::cin, debtorName);

    std::cout << "Введите сумму долга: ";
    while (!(std::cin >> totalDebt) || totalDebt <= 0) {
        std::cout << "Неверный ввод. Введите положительное число для суммы долга: ";
    }

    while (totalDebt > 0) {
        std::cout << "Должник: " << debtorName << ", оставшаяся сумма долга: " << totalDebt << "\n";
        std::cout << "Введите сумму погашения: ";

        while (!(std::cin >> payment) || payment < 0) {
            std::cout << "Неверный ввод. Введите неотрицательное число для суммы погашения: ";
        }

        if (payment < totalDebt) {
            totalDebt -= payment;
            std::cout << "Остаток задолженности: " << totalDebt << "\n";
        } else if (payment == totalDebt) {
            std::cout << "Долг полностью погашен. Спасибо!";
            totalDebt = 0;
        } else {
            int excess = payment - totalDebt;
            std::cout << "Долг полностью погашен. Остаток на счёте: " << excess << "\n";
            totalDebt = 0;
        }
    }

    return 0;
}
