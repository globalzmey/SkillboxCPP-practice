#include <iostream>

int main() {

    int beginHeight;
    std::cout << "Начальная высота бамбука (см): ";
    std::cin >> beginHeight;
    int dailyGrowth;
    std::cout << "Ежедневный рост (см в день): ";
    std::cin >> dailyGrowth;
    int nightFade;
    std::cout << "Размер съедаемого гусеницами бамбука за одну ночь (см): ";
    std::cin >> nightFade;
    int countOfDays;
    std::cout << "Растим дней: ";
    std::cin >> countOfDays;

    int endHeight = beginHeight + (dailyGrowth - nightFade) * countOfDays + dailyGrowth / 2;
    std::cout << "Высота бымбука к середине третьего дня " << endHeight << " см.\n";

    return 0;
}
