#include <iostream>

int main()
{
    int itemPrice = 8192;
    int deliveryCost = 500;
    int discountValue = 819;
    int totalPrice = itemPrice + deliveryCost - discountValue;

    std::cout << "Калькулятор полной стоимости товаров с учетом скидок и доставки.\n";
    std::cout << "Введите стоимость товара: " << itemPrice << "\n";
    std::cout << "Введите стоимость доставки: " << deliveryCost << "\n";
    std::cout << "Введите размер скидки: " << discountValue << "\n";
    std::cout << "-----Считаем-----\n";
    std::cout << "Итого: " << totalPrice << "\n";

}
