#include <iostream>
#include <string>

int main() {
    const int NUM_FLATS = 10;
    std::string surnames[NUM_FLATS];

    std::cout << "Введите фамилии жильцов (10 штук):\n";
    for (int i = 0; i < NUM_FLATS; ++i) {
        std::cin >> surnames[i];
    }

    std::cout << "Введите три номера квартир:\n";
    for (int i = 0; i < 3; ++i) {
        int flatNumber;
        std::cin >> flatNumber;

        if (flatNumber >= 1 && flatNumber <= NUM_FLATS) {
            std::cout << surnames[flatNumber - 1] << std::endl;
        } else {
            std::cout << "Некорректный номер квартиры. Попробуйте снова.\n";
        }
    }

    return 0;
}