#include <iostream>

int main() {
    int M, N;

    while (true) {
        std::cout << "Введите числитель: ";
        std::cin >> M;

        std::cout << "Введите знаменатель: ";
        std::cin >> N;

        if (N == 0) {
            std::cout << "Ошибка: знаменатель не может быть равен нулю. Попробуйте снова.\n";
            continue;
        }

        int a = (M < 0) ? -M : M;
        int b = (N < 0) ? -N : N;

        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }

        int divisor = a;

        M /= divisor;
        N /= divisor;

        if (N < 0) {
            M = -M;
            N = -N;
        }

        std::cout << "Результат: " << M << " / " << N << "\n";
        break;
    }

    return 0;
}
