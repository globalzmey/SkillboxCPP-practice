#include <iostream>

void reverseArray(int* array) {
    if (array == NULL) {
        return;
    }

    const int size = 10;

    for (int i = 0; i < size / 2; ++i)
    {
        int temp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = temp;
    }
}

int main() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    reverseArray(array);

    for (int i = 0; i < 10; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;

    return 0;

}