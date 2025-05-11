#include <iostream>
#include <string>
#include <map>
#include <vector>

int main() {
    std::map<std::string, std::string> phoneToName;
    std::map<std::string, std::vector<std::string>> nameToPhones;

    std::string query;
    while (std::getline(std::cin, query)) {
        if (query.empty())
            continue;

        if (query == "exit") {
            break;
        }

        size_t spacePos = query.find(' ');
        if (spacePos == std::string::npos) {
            // Запрос типа 2 или 3 (только номер или только фамилия)
            if (query.find('-') != std::string::npos) {
                // Запрос типа 2: поиск по номеру
                auto it = phoneToName.find(query);
                if (it != phoneToName.end()) {
                    std::cout << it->second << std::endl;
                }
            } else {
                // Запрос типа 3: поиск по фамилии
                auto it = nameToPhones.find(query);
                if (it != nameToPhones.end()) {
                    for (size_t i = 0; i < it->second.size(); ++i) {
                        if (i != 0)
                            std::cout << " ";
                        std::cout << it->second[i];
                    }
                    std::cout << std::endl;
                }
            }
        } else {
            // Запрос типа 1: добавление записи
            std::string phone = query.substr(0, spacePos);
            std::string name = query.substr(spacePos + 1);

            // Обновляем phoneToName
            phoneToName[phone] = name;

            // Обновляем nameToPhones
            auto &phones = nameToPhones[name];
            bool found = false;
            for (const auto &p : phones) {
                if (p == phone) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                phones.push_back(phone);
            }
        }
    }

    return 0;
}