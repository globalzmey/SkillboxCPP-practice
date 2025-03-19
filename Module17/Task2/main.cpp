#include <iostream>

void reverseArray(int *array, int arraySize) {
    int arrayReverse[arraySize];
    int j = arraySize - 1;
    for (int i = 0; i < arraySize; i++) {
        arrayReverse[i] = array[j];
        j--;
    }

    for (int i = 0; i < arraySize; i++) {
        array[i] = arrayReverse[i];
    }

}

int main() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arraySize = sizeof(array) / sizeof(array[0]);

    reverseArray(array, arraySize);

    for (int i = 0; i < arraySize; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << "\n";

    return 0;

}