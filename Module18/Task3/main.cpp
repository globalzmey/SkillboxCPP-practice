#include <iostream>

void countEvenDigits(long long n, int& ans) {
    if (n == 0) {
        return;
    }

    int digit = n % 10;

    if (digit % 2 == 0) {
        ans++;
    }

    countEvenDigits(n / 10, ans);
}

int main() {
    long long number;
    std::cout << "Введите число: ";
    std::cin >> number;
    
    int evenCount = 0;
    countEvenDigits(number, evenCount);
    
    std::cout << "Количество чётных цифр: " << evenCount << std::endl;
    
    return 0;
}