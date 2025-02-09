#include <iostream>
int main() {
    int number;
    std::cout << "Input number (1-3999): ";
    std::cin >> number;

    if (number < 1 || number > 3999) {
        std::cout << "The number must be from 1 to 3999!\n";
        return 0;
    }

    std::string roman = "";

    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    for (int i = 0; i < 13; ++i) {
        while (number >= values[i]) {
            roman += symbols[i];
            number -= values[i];
        }
    }

    std::cout << "Roman numerals: " << roman << "\n";

    return 0;
}