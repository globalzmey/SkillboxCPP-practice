#include <iostream>

int main() {
    int a = 42;
    int b = 153;

    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";
    std::cout << "--- Меняем местами ---\n";
    a = a + b;
    b = a - b;
    a = a - b;
    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";

    return 0;
}
