#include <iostream>
#include <cmath>

int main() {
    const double cubeSide = 5.0;

    double x, y, z;
    std::cout << "Введите размеры бруска:\n";
    
    std::cout << "X: ";
    std::cin >> x;
    while (x <= 0) {
        std::cout << "Введите корректное значение длины бруска: ";
        std::cin >> x;
    }
    
    std::cout << "Y: ";
    std::cin >> y;
    while (y <= 0) {
        std::cout << "Введите корректное значение ширины бруска: ";
        std::cin >> y;
    }
    std::cout << "Z: ";
    std::cin >> z;
    while (z <= 0) {
        std::cout << "Введите корректное значение высоты бруска: ";
        std::cin >> z;
    }

    int countCubesX = floor(x / cubeSide);
    int countCubesY = floor(y / cubeSide);
    int countCubesZ = floor(z / cubeSide);

    int totalCubes = countCubesX * countCubesY * countCubesZ;

    std::cout << "Из этого бруска можно изготовить " << totalCubes << " кубиков.\n";

    int maxCubesInSet = 0;
    for (int n = 1; std::pow(n, 3) <= totalCubes; ++n) {
        maxCubesInSet = std::pow(n, 3);
    }

    if (maxCubesInSet >= 8) {
        std::cout << "Из них можно составить набор из " << maxCubesInSet << " кубиков.\n";
    } else {
        std::cout << "Из этих кубиков нельзя составить набор.\n";
    }

    return 0;
}
