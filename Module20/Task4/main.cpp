#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <string>

const std::vector<int> DENOMINATIONS = {5000, 2000, 1000, 500, 200, 100};
const int MAX_BILLS = 1000;
const std::string ATM_STATE_FILE = "atm_state.bin";

void loadATMState(int bills[], int &totalBills, int &totalAmount) {
    std::ifstream file(ATM_STATE_FILE, std::ios::binary);

    totalBills = 0;
    totalAmount = 0;

    if (file) {
        for (int i = 0; i < DENOMINATIONS.size(); i++) {
            file.read(reinterpret_cast<char *>(&bills[i]), sizeof(int));
            totalBills += bills[i];
            totalAmount += DENOMINATIONS[i] * bills[i];
        }
    } else {
        for (int i = 0; i < DENOMINATIONS.size(); i++) {
            bills[i] = 0;
        }
    }
}

void saveATMState(const int bills[]) {
    std::ofstream file(ATM_STATE_FILE, std::ios::binary);

    for (int i = 0; i < DENOMINATIONS.size(); i++) {
        file.write(reinterpret_cast<const char *>(&bills[i]), sizeof(int));
    }
}

void printATMState(const int bills[], int totalBills, int totalAmount) {
    std::cout << "\nТекущее состояние банкомата:\n";
    for (int i = 0; i < DENOMINATIONS.size(); i++) {
        std::cout << "Купюр " << DENOMINATIONS[i] << " руб.: " << bills[i] << "\n";
    }
    std::cout << "Всего купюр: " << totalBills << "\n";
    std::cout << "Общая сумма: " << totalAmount << " руб.\n\n";
}

void fillATM(int bills[], int &totalBills, int &totalAmount) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, DENOMINATIONS.size() - 1);

    int billsToAdd = MAX_BILLS - totalBills;

    while (billsToAdd > 0) {
        int index = dist(gen);
        bills[index]++;
        totalBills++;
        totalAmount += DENOMINATIONS[index];
        billsToAdd--;
    }

    std::cout << "Банкомат заполнен.\n";
}

bool withdrawMoney(int bills[], int &totalBills, int &totalAmount, int amount) {
    if (amount % 100 != 0) {
        std::cout << "Сумма должна быть кратна 100 руб.\n";
        return false;
    }

    if (amount > totalAmount) {
        std::cout << "В банкомате недостаточно средств.\n";
        return false;
    }

    int tempBills[6];
    int tempTotalBills = totalBills;
    int tempTotalAmount = totalAmount;
    for (int i = 0; i < DENOMINATIONS.size(); i++) {
        tempBills[i] = bills[i];
    }

    int billsToGive[6] = {0};
    int remainingAmount = amount;

    for (int i = 0; i < DENOMINATIONS.size(); i++) {
        if (remainingAmount <= 0)
            break;

        int denom = DENOMINATIONS[i];
        int needed = remainingAmount / denom;
        int available = tempBills[i];
        int toGive = (needed < available) ? needed : available;

        if (toGive > 0) {
            billsToGive[i] = toGive;
            tempBills[i] -= toGive;
            tempTotalBills -= toGive;
            tempTotalAmount -= denom * toGive;
            remainingAmount -= denom * toGive;
        }
    }

    if (remainingAmount == 0) {
        for (int i = 0; i < DENOMINATIONS.size(); i++) {
            bills[i] = tempBills[i];
        }
        totalBills = tempTotalBills;
        totalAmount = tempTotalAmount;

        std::cout << "Выдано:\n";
        for (int i = 0; i < DENOMINATIONS.size(); i++) {
            if (billsToGive[i] > 0) {
                std::cout << billsToGive[i] << " x " << DENOMINATIONS[i] << " руб.\n";
            }
        }
        return true;
    } else {
        std::cout << "Невозможно выдать запрошенную сумму имеющимися купюрами.\n";
        return false;
    }
}

int main() {
    int bills[6] = {0};
    int totalBills = 0;
    int totalAmount = 0;

    loadATMState(bills, totalBills, totalAmount);
    printATMState(bills, totalBills, totalAmount);

    std::string command;
    while (true) {
        std::cout << "Введите команду:\n";
        std::cout << "+ - пополнить банкомат\n";
        std::cout << "- - снять деньги\n";
        std::cout << "q - выйти\n";
        std::cout << "> ";
        std::cin >> command;

        if (command == "q") {
            saveATMState(bills);
            std::cout << "Состояние банкомата сохранено. Выход...\n";
            break;
        } else if (command == "+") {
            fillATM(bills, totalBills, totalAmount);
            printATMState(bills, totalBills, totalAmount);
        } else if (command == "-") {
            int amount;
            std::cout << "Введите сумму для снятия (кратную 100 руб.): ";
            std::cin >> amount;

            if (withdrawMoney(bills, totalBills, totalAmount, amount)) {
                printATMState(bills, totalBills, totalAmount);
            }
        } else {
            std::cout << "Неизвестная команда. Попробуйте снова.\n";
        }
    }

    return 0;
}