#include <iostream>

void findPair(int a[], int size, int result) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (a[i] + a[j] == result) {
                std::cout << a[i] << " " << a[j] << std::endl;
                return;
            }
        }
    }
}

int main() {
    int a[] = {2, 7, 11, 15};
    int result = 9;
    int size = sizeof(a) / sizeof(a[0]);

    findPair(a, size, result);
    
    return 0;
}