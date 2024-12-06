#include <iostream>

int main() {
    int a = 42;
    int b = 153;

    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";
    std::cout << "--- Меняем местами ---\n";
    int tmpValue = a;
    a = b;
    b = tmpValue;
    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";

    return 0;
}
