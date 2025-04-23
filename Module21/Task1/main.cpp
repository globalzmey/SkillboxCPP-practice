#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

// Структура для хранения записи ведомости
struct Record {
    std::string fullName;
    std::string date;
    double amount;
};

// Функция для чтения записей из файла
std::vector<Record> readRecords(const std::string &fileName) {
    std::vector<Record> records;
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл для чтения." << std::endl;
        return records;
    }

    while (!file.eof()) {
        Record record;
        file >> record.fullName;
        if (file.eof())
            break;
        std::string lastName;
        file >> lastName;
        record.fullName += " " + lastName;
        file >> record.date >> record.amount;
        records.push_back(record);
    }

    file.close();
    return records;
}

// Функция для записи новой записи в файл
void addRecord(const std::string &fileName, const Record &record) {
    std::ofstream file(fileName, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл для записи." << std::endl;
        return;
    }

    file << record.fullName << " " << record.date << " " << record.amount << "\n";
    file.close();
}

// Функция для отображения всех записей
void listRecords(const std::vector<Record> &records) {
    if (records.empty()) {
        std::cout << "Ведомость пуста." << std::endl;
        return;
    }

    for (const auto &record : records) {
        std::cout << "Имя: " << record.fullName
                  << ", Дата: " << record.date
                  << ", Сумма: " << record.amount << " руб." << std::endl;
    }
}

int main() {
    std::string command;
    std::cout << "Введите команду (list или add): ";
    std::cin >> command;

    const std::string fileName = "ledger.txt";

    if (command == "list") {
        std::vector<Record> records = readRecords(fileName);
        listRecords(records);
    }
    else if (command == "add") {
        Record newRecord;
        std::cin.ignore();
        std::cout << "Введите имя и фамилию: ";
        std::getline(std::cin, newRecord.fullName);
        std::cout << "Введите дату (ДД.ММ.ГГГГ): ";
        std::cin >> newRecord.date;
        std::cout << "Введите сумму: ";
        std::cin >> newRecord.amount;

        addRecord(fileName, newRecord);
        std::cout << "Запись успешно добавлена." << std::endl;
    } else {
        std::cerr << "Ошибка: Неизвестная команда." << std::endl;
    }

    return 0;
}