#include <iostream>


int main() {
    int manPopulation, manPerDay, numberOfBarbers, menToBarbers, barbersNeeds;
    int clientPerHour = 1;
    int workTime = 8;
    int numberOfVisitPerMonth = 1;

    std::cout << "Сколько мужчин проживает в городе: ";
    std::cin >> manPopulation;
    std::cout << "Сколько барберов работает в барбершопах: ";
    std::cin >> numberOfBarbers;
    manPerDay = manPopulation/(30*numberOfVisitPerMonth);
    if (manPopulation%(30*numberOfVisitPerMonth) != 0) {
        manPerDay += 1;
    }
    menToBarbers = clientPerHour * workTime * numberOfBarbers;
    if (menToBarbers >=manPerDay) {
        std::cout << "Барберов достаточно!\n";
    }
    else {
        barbersNeeds = manPerDay / workTime;
    if (manPerDay % workTime != 0) { barbersNeeds += 1;}
        barbersNeeds /= clientPerHour;
    if (barbersNeeds % clientPerHour != 0) {
        barbersNeeds += 1;
    }
    numberOfBarbers = barbersNeeds - numberOfBarbers;
    std::cout << "Вам нехватает еще "  << numberOfBarbers << " барберa(ов).\n";
    }

    return 0;
}
