#include <iostream>

int main() {
    std::cout << "Загадайте число от 0 до 63.\n";
    std::cout << "Ответьте на вопросы 'да' или 'нет'.\n";

    int low = 0;
    int high = 63;
    std::string response;

    while (low < high) {
        int mid = (low + high) / 2;
        std::cout << "Ваше число больше " << mid << "? (да/нет): ";
        std::cin >> response;

        while (response != "да" && response != "нет") {
            std::cout << "Пожалуйста, отвечайте только 'да' или 'нет'. Попробуйте снова: ";
            std::cin >> response;
        }

        if (response == "да") {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    std::cout << "Ваше число: " << low << "\n";

    return 0;
}
