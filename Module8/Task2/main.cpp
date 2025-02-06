#include <iostream>

int main() {
    double health, magicResistance;

    std::cout << "Введите уровень здоровья орка от 0 до 1: ";
    std::cin >> health;
    while (health < 0 || health > 1){
        std::cout << "Введиите корректное значение здоровья орка от 0 до 1: ";
        std::cin >> health;
    }

    std::cout << "Введите уровень сопротивляемости орка от 0 до 1: ";
    std::cin >> magicResistance;
    while (magicResistance < 0 || magicResistance > 1){
        std::cout << "Введиите корректное значение сопротивляемости орка от 0 до 1: ";
        std::cin >> magicResistance;
    }

    while (health > 0){
        double fireBall, damage;

        std::cout << "Введите уровень мощности огненного шара от 0 до 1: ";
        std::cin >> fireBall;
        while (fireBall < 0 || fireBall > 1){
            std::cout << "Введите корректное значение уровня мощности огненного шара от 0 до 1: ";
            std::cin >> fireBall;
    }

        if (fireBall < 1) {
            damage = fireBall * magicResistance;
            std::cout << "Урон " << fireBall << " сопротивляемость " << magicResistance << " по орку будет нанесено " << damage << " урона.\n";
        } else {
            damage = fireBall - magicResistance;
            std::cout << "Урон " << fireBall << " сопротивляемость " << magicResistance << " по орку будет нанесено " << damage << " урона.\n";
        }
        health -= damage;
    }

    std::cout << "Orc's dead, baby. Orc's dead.\n";

    return 0;
}
