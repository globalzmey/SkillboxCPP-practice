#include <iostream>
#include <vector>

int main() {
    int vSize;

    std::cout << "Input vector size: ";
    std::cin >> vSize;

    std::vector<int> vect(vSize);
    std::cout << "Input elements: ";
    for (int i = 0; i < vSize; i++) {
        std::cin >> vect[i]; 
    }

    int X;
    std::cout << "Input number to delete: ";
    std::cin >> X;

    int writeIndex = 0;

    for (int readIndex = 0; readIndex < vSize; ++readIndex) {
        if (vect[readIndex] != X) {
            vect[writeIndex++] = vect[readIndex];
        }
    }

    while (vect.size() > writeIndex) {
        vect.pop_back();
    }

    std::cout << "Result: ";
    for (int num : vect) {
        std::cout << num << " ";
    }
    
    std::cout << std::endl;

    return 0;

}