#include <iostream>
#include <string>

enum note {
    DO = 1 << 0,  // 1
    RE = 1 << 1,  // 2
    MI = 1 << 2,  // 4
    FA = 1 << 3,  // 8
    SOL = 1 << 4, // 16
    LA = 1 << 5,  // 32
    SI = 1 << 6   // 64
};

int main() {
    std::cout << "Введите аккорд (цифры от 1 до 7): ";
    std::string input;
    std::cin >> input;

    int notes = 0;

    for (char ch : input) {
        if (ch >= '1' && ch <= '7') {
            int index = ch - '1';
            notes |= (1 << index);
        }
    }

    std::cout << "Ноты в аккорде: ";
    if (notes & DO)
        std::cout << "DO ";
    if (notes & RE)
        std::cout << "RE ";
    if (notes & MI)
        std::cout << "MI ";
    if (notes & FA)
        std::cout << "FA ";
    if (notes & SOL)
        std::cout << "SOL ";
    if (notes & LA)
        std::cout << "LA ";
    if (notes & SI)
        std::cout << "SI ";

    std::cout << std::endl;

    return 0;
}