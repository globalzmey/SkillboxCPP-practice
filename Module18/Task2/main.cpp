#include <iostream>

int countJumpWays(int n, int k = 3) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    
    int ways = 0;
    for (int i = 1; i <= k; i++) {
        ways += countJumpWays(n - i, k);
    }
    
    return ways;
}

int main() {
    int n, k;
    char comma;

    std::cout << "Ввод: ";
    std::cin >> n >> comma >> k;

    std::cout << "Вывод: " << countJumpWays(n, k) << std::endl;
              
    return 0;
}