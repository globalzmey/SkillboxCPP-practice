#include <iostream>

int main() {
    int passengerTotal = 0;
    int passengerCount = 0;
    int passengerEnter = 0;
    int passengerExit = 0;
    int ticketPrice = 20;
    int totalIncome = 0;
    std::string stationOne = "\"Улица Пограммистов\"";
    std::string stationTwo = "\"Улица Алгоритмов\"";
    std::string stationThree = "\"Улица Ады\"";
    std::string stationFour = "\"Деление на Ноль\"";

    std::cout << "Прибываем на остановку " << stationOne << ". В салоне пассажиров: " << passengerTotal << "\n";
    std::cout << "Сколько пассажиров вышло на остановке? ";
    std::cin >> passengerExit;
    std::cout << "Сколько пассажиров зашло на остановке? ";
    std::cin >> passengerEnter;
    passengerTotal = passengerTotal + passengerEnter;
    passengerCount += passengerEnter;
    std::cout << "Отправляемся с остановки " << stationOne << ". В салоне пассажиров: "<< passengerTotal << "\n";
    std::cout << "-------- Едем ----------\n";
    std::cout << "Прибываем на остановку " << stationTwo << ". В салоне пассажиров: " << passengerTotal << "\n";
    std::cout << "Сколько пассажиров вышло на остановке? ";
    std::cin >> passengerExit;
    std::cout << "Сколько пассажиров зашло на остановке? ";
    std::cin >> passengerEnter;
    passengerTotal = passengerTotal - passengerExit + passengerEnter;
    passengerCount += passengerEnter;
    std::cout << "Отправляемся с остановки " << stationTwo << ". В салоне пассажиров: "<< passengerTotal << "\n";
    std::cout << "-------- Едем ----------\n";
    std::cout << "Прибываем на остановку " << stationThree << ". В салоне пассажиров: " << passengerTotal << "\n";
    std::cout << "Сколько пассажиров вышло на остановке? ";
    std::cin >> passengerExit;
    std::cout << "Сколько пассажиров зашло на остановке? ";
    std::cin >> passengerEnter;
    passengerTotal = passengerTotal - passengerExit + passengerEnter;
    passengerCount += passengerEnter;
    std::cout << "Отправляемся с остановки " << stationThree << ". В салоне пассажиров: "<< passengerTotal << "\n";
    std::cout << "-------- Едем ----------\n";
    std::cout << "Прибываем на остановку " << stationFour << ". В салоне пассажиров: " << passengerTotal << "\n";
    std::cout << "Сколько пассажиров вышло на остановке? ";
    std::cin >> passengerExit;
    std::cout << "Сколько пассажиров зашло на остановке? ";
    std::cin >> passengerEnter;
    passengerTotal = passengerTotal - passengerExit + passengerEnter;
    passengerCount += passengerEnter;
    std::cout << "Отправляемся с остановки " << stationFour << ". В салоне пассажиров: "<< passengerTotal << "\n";

    totalIncome = ticketPrice * passengerCount;
    std::cout << "Всего заработали: " << totalIncome << " руб.\n";
    int driverSalary = totalIncome / 4;
    std::cout << "Зарплата водителя: " << driverSalary << " руб.\n";
    int fuelPayment = totalIncome / 5;
    std::cout << "Расходы на топливо: " << fuelPayment << " руб.\n";
    int taxesPayment = totalIncome / 5;
    std::cout << "Налоги: " << taxesPayment << " руб.\n";
    int renovationPayment = totalIncome / 5;
    std::cout << "Расходы на ремонт машины: " << renovationPayment << " руб.\n";
    int totalProfit = totalIncome - driverSalary - fuelPayment - taxesPayment - renovationPayment;
    std::cout << "Итого доход: " << totalProfit << " руб.\n";

    return 0;
}
