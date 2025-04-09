#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>

bool isValidDate(const std::string &date) {
    if (date.size() != 10 || date[2] != '.' || date[5] != '.') {
        return false;
    }

    for (int i = 0; i < 10; ++i) {
        if (i == 2 || i == 5)
            continue;
        if (!std::isdigit(date[i])) {
            return false;
        }
    }

    int day = std::stoi(date.substr(0, 2));
    int month = std::stoi(date.substr(3, 2));
    int year = std::stoi(date.substr(6, 4));

    if (month < 1 || month > 12 || day < 1 || day > 31 || year < 1900 || year > 2100) {
        return false;
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }

    if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > 29 || (day > 28 && !isLeapYear)) {
            return false;
        }
    }

    return true;
}

bool isValidAmount(const std::string &amountStr, double &amount)
{
    bool hasDecimalPoint = false;
    for (char c : amountStr) {
        if (!std::isdigit(c)) {
            if (c == '.' && !hasDecimalPoint) {
                hasDecimalPoint = true;
            } else {
                return false;
            }
        }
    }

    std::stringstream ss(amountStr);
    ss >> amount;

    return amount > 0;
}

int main()
{
    std::string fullName, date, amountStr;
    double amount;

    std::cout << "Введите имя и фамилию получателя: ";
    std::getline(std::cin, fullName);

    std::cout << "Введите дату выдачи (ДД.ММ.ГГГГ): ";
    std::getline(std::cin, date);

    std::cout << "Введите сумму выплаты: ";
    std::getline(std::cin, amountStr);

    if (!isValidDate(date))
    {
        std::cerr << "Ошибка: Некорректный формат даты." << std::endl;
        return 1;
    }

    if (!isValidAmount(amountStr, amount))
    {
        std::cerr << "Ошибка: Некорректная сумма." << std::endl;
        return 1;
    }

    std::ofstream file("ledger.txt", std::ios::app);
    if (!file.is_open())
    {
        std::cerr << "Ошибка: Не удалось открыть файл." << std::endl;
        return 1;
    }

    file << fullName << " " << date << " " << amount << "\n";
    file.close();

    std::cout << "Запись успешно добавлена в ведомость." << std::endl;

    return 0;
}