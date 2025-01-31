#include <iostream>

int main() {
    int N, X;

    std::cout << "Введите количество бактерий: ";
    std::cin >> N;
    while (N <= 0) {
        std::cout << "Ошибка: количество бактерий должно быть больше 0. Введите снова: ";
        std::cin >> N;
    }

    std::cout << "Введите количество антибиотика: ";
    std::cin >> X;
    while (X < 0) {
        std::cout << "Ошибка: количество антибиотика не может быть отрицательным. Введите снова: ";
        std::cin >> X;
    }

    int hour = 0;
    int antibiotic_effect = 10;
    int fagPower = X * antibiotic_effect;
    int timeActive = 10;

    while (N > 0 && hour < timeActive) {
        hour++;
        N *= 2;
        N -= fagPower;
        fagPower -= X;

        if (N > 0) {
            std::cout << "После " << hour << " часа бактерий осталось " << N << "\n";
        } else {
            N = 0;
            std::cout << "После " << hour << " часа бактерий осталось " << N << "\n";
        }
    }

    if (N == 0) {
        std::cout << "Все бактерии уничтожены через " << hour << " часов." << "\n";
    } else {
        std::cout << "Антибиотик перестал действовать. Через " << hour << " часов осталось " << N << " бактерий." << "\n";
    }

    return 0;
}
