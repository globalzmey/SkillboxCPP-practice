#include <iostream>

int main() {
    int firstPersonSallary, secondPersonSallary, thirdPersonSallary, highestSalary, lowestSalary;

    std::cout << "Зарплата сотрудника 1: ";
    std::cin >> firstPersonSallary;
    std::cout << "Зарплата сотрудника 2: ";
    std::cin >> secondPersonSallary;
    std::cout << "Зарплата сотрудника 3: ";
    std::cin >> thirdPersonSallary;
    std::cout <<"----------Счиаем----------\n";

    highestSalary = firstPersonSallary;
    lowestSalary = firstPersonSallary;
    if (highestSalary <= secondPersonSallary) {
        highestSalary = secondPersonSallary;
    }

    if (highestSalary <= thirdPersonSallary) {
        highestSalary = thirdPersonSallary;
    }
    if (lowestSalary >= secondPersonSallary) {
        lowestSalary = secondPersonSallary;
    }
    else if (lowestSalary >= thirdPersonSallary) {
        lowestSalary = thirdPersonSallary;
    }
    std::cout << "Самая высокая зарплата в отделе: " << highestSalary << "\n";
    std::cout << "Разница между самой высокой и самой низкой зарплатой в отделе: " << highestSalary - lowestSalary << "\n";
    std::cout << "Средняя зарплата составляет " << (firstPersonSallary + secondPersonSallary + thirdPersonSallary) / 3 << "\n";

    return 0;
}
