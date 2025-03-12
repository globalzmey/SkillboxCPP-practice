#include <iostream>
#include <cmath>

void printByAbsoluteValue(int arr[], int n) {
    if (n == 0) return;
    int right = 0;
    while (right < n && arr[right] < 0) {
        right += 1;
    }

    int left = right - 1;

    bool isFirst = true;

    std::cout << "Вывод: ";
    while (left >= 0 || right < n) {
        if (left >= 0 && right < n) {
            if (std::abs(arr[left]) <= std::abs(arr[right])) {
                if (!isFirst) std::cout << ", ";
                std::cout << arr[left];
                left -= 1;
                isFirst = false;
            } else {
                if (!isFirst) std::cout << ", ";
                std::cout << arr[right];
                right += 1;
                isFirst = false;
            }
        } else if (left >= 0) {
            if (!isFirst) std::cout << ", ";
            std::cout << arr[left];
            left -= 1;
            isFirst = false;
        } else if (right < n) {
            if (!isFirst) std::cout << ", ";
            std::cout << arr[right];
            right += 1;
            isFirst = false;
        }
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {-100, -50, -5, 1, 10, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Вывод исходного массива
    std::cout << "Массив {";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i];
        if (i != n - 1) std::cout << ", ";
    }
    std::cout << "}" << std::endl;

    printByAbsoluteValue(arr, n);

    return 0;
}