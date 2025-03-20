#include <iostream>

void swap(int* a, int* b) {
    if (a == NULL || b == NULL) {
        return;
    }

    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 10;
    int b = 20;

    swap(&a, &b);

    std::cout << "a = " << a << ", b = " << b << std::endl;

    return 0;
    
}