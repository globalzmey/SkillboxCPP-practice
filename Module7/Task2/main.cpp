#include <iostream>

int main() {
    const int AMERICANO_WATER = 300;
    const int LATTE_WATER = 30;
    const int LATTE_MILK = 270;

    int water, milk;

    int americano_count = 0, latte_count = 0;

    std::cout << "Введите количество воды в мл: ";
    std::cin >> water;
    if (water <= 0) {
        do {
            std::cout << "Введите корректное количество воды в мл: ";
            std::cin >> water;
        } while (water <= 0);
    }

    std::cout << "Введите количество молока в мл: ";
    std::cin >> milk;
    if (milk <= 0) {
        do {
            std::cout << "Введите корректное количество молока в мл: ";
            std::cin >> milk;
        } while (milk <= 0);
    }

    while (water > AMERICANO_WATER || (water > LATTE_WATER && milk > LATTE_MILK)) {

        int choice;
        std::cout << "Выберите напиток (1 — американо, 2 — латте): ";
        std::cin >> choice;

        if (choice == 1) {
            if (water >= AMERICANO_WATER) {
                water -= AMERICANO_WATER;
                americano_count++;
                std::cout << "Ваш напиток готов\n";
            } else {
                std::cout << "Не хватает воды.\n";
            }
        } else if (choice == 2) {
            if (water >= LATTE_WATER && milk >= LATTE_MILK) {
                water -= LATTE_WATER;
                milk -= LATTE_MILK;
                latte_count++;
                std::cout << "Ваш напиток готов.\n";
            } else if (water < LATTE_WATER) {
                std::cout << "Не хватает воды.\n";
            } else {
                std::cout << "Не хватает молока.\n";
            }
        }
    }

    std::cout << "***Отчёт***\n";
    std::cout << "Ингредиентов осталось:\n";
    std::cout << "\tВода: " << water << " мл\n";
    std::cout << "\tМолоко: " << milk << " мл\n";
    std::cout << "Кружек американо приготовлено: " << americano_count << "\n";
    std::cout << "Кружек латте приготовлено: " << latte_count << "\n";

    return 0;
}
