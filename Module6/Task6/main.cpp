#include <iostream>

int main() {
    long long X;
    long long Y;
    int P;

    std::cout << "Введите размер вклада: ";
    std::cin >> X;
    std::cout << "Введите процентную ставку: ";
    std::cin >> P;
    std::cout << "Введите желаемую сумму: ";
    std::cin >> Y;

    int years = 0;

    if (X >= Y) {
        std::cout << "Придётся подождать: 0 лет\n";
        return 0;
    }

    while (X < Y) {
        long long interest = (X * P) / 100;
        X += interest;
        years++;
    }

    std::cout << "Придётся подождать: " << years << " лет.\n";

    return 0;
}
