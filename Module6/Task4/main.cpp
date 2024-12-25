#include <iostream>

int main() {
    int ticket;

    std::cout << "Введите номер билета: ";
    std::cin >> ticket;

    int temp = ticket;
    int digits_count = 0;
    while (temp > 0) {
        temp /= 10;
        digits_count++;
    }

    if (!(digits_count % 2 != 0)) {
        int half = digits_count / 2;
        int left_sum = 0, right_sum = 0;

        for (int i = 0; i < digits_count; i++) {
            int digit = ticket % 10;
            ticket /= 10;

            if (i < half) {
                right_sum += digit;
            } else {
                left_sum += digit;
            }
        }

        if (left_sum == right_sum) {
            std::cout << "Билет счастливый!\n";
        } else {
            std::cout << "Не в этот раз!\n";
        }
    } else {
            std::cout << "Номер билета должен быть с чётным количеством цифр!\n";
        }

    return 0;
}
