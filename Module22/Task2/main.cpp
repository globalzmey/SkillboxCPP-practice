#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<std::string, int> registry; // Хранит фамилии и их количество в очереди
    std::string input;

    while (std::cin >> input) {
        if (input == "Next") {
            if (!registry.empty()) {
                // Получаем первую фамилию в лексикографическом порядке
                auto first = registry.begin();
                std::cout << first->first << std::endl;

                // Уменьшаем счетчик или удаляем фамилию из очереди
                if (first->second > 1) {
                    first->second--;
                } else{
                    registry.erase(first);
                }
            }
        } else if (input == "Exit") {
            break;
        } else {
            // Добавляем фамилию в очередь
            registry[input]++;
        }
    }

    return 0;
}