#include <iostream>

int x = 10;
int y = 7;
const int LENGTH = 20;
const int WIDTH = 15;

int main() {
    std::cout << "Команды движения марсохода (W - север, A - запад, S - йуг, D - восток, Q - выйти)\n";
    std::cout << "[Программа]: Марсоход находится на позиции " << x << ", " << y << " ";

    char command;

    while (true) {
        std::cout << "введите команду:\n[Оператор]: ";
        std::cin >> command;

        if (command == 'Q') {
            std::cout << "Выход из программы.\n";
            break;
        }

        if (command == 'W') {
            if (y < WIDTH) {
                y++;
            } else {
                std::cout << "Достигнута верхняя стена. Марсоход не может двигаться дальше на север.\n";
            }
        } else if (command == 'S') {
            if (y > 1) {
                y--;
            } else {
                std::cout << "Достигнута нижняя стена. Марсоход не может двигаться дальше на юг.\n";
            }
        } else if (command == 'A') {
            if (x > 1) {
                x--;
            } else {
                std::cout << "Достигнута левая стена. Марсоход не может двигаться дальше на запад.\n";
            }
        } else if (command == 'D') {
            if (x < LENGTH) {
                x++;
            } else {
                std::cout << "Достигнута правая стена. Марсоход не может двигаться дальше на восток.\n";
            }
        } else {
            std::cout << "Ошибка: некорректная команда. Используйте W, A, S, D.\n";
        }

        std::cout << "[Программа]: Марсоход находится на позиции: (" << x << ", " << y << ") ";
    }

    return 0;
}
