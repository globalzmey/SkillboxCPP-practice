#include <iostream>

int main() {
    int N;

    while (true) {
        std::cout << "Введите номер последовательности: ";
        std::cin >> N;

        unsigned long long a = 1, b = 1, c = 1;

        if (N == 1 || N == 2) {
            c = 1;
        } else {
            for (int i = 3; i <= N; i++) {
                c = a + b;
                a = b;
                b = c;

                if (c > 2147483647) {
                    std::cout << "Число в последовательности: " << c << " (Превышает предел 2 147 483 647)\n";
                    break;
                }
            }
        }

        if (c <= 2147483647) {
            std::cout << "Число в последовательности: " << c << "\n";
        }

        break;
    }

    return 0;
}
