#include <iostream>

int main()
{
    int fullPrice = 4000000;
    int entranceCount = 10;
    int appartmentCount = 40;
    int appartmentPayment = fullPrice / (entranceCount * appartmentCount);

    std::cout << "Приветствуем вас в калькуляторе квартплаты! \n";
    std::cout << "Введите сумму, указанную в квитанции: " << fullPrice << "\n";
    std::cout << "Сколько подъездов в вашем доме? " << entranceCount  << "\n";
    std::cout << "Сколько квартир в каждом подъезде? " << appartmentCount << "\n";
    std::cout << "----Считаем-----\n";
    std::cout << "Каждая квартира должна заплатить по " << appartmentPayment << " руб.\n";
}
