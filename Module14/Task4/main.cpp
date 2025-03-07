#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<float>> a(4, std::vector<float>(4));
    std::vector<float> b(4);
    std::vector<float> c(4);

    std::cout << "Введите матрицу А (4x4):" << std::endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cin >> a[i][j];
        }
    }

    std::cout << "Введите вектор В (4 компонента):" << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cin >> b[i];
    }

    for (int i = 0; i < 4; ++i) {
        float accumulator = 0.0f;
        for (int j = 0; j < 4; ++j) {
            accumulator += a[i][j] * b[j];
        }
        c[i] = accumulator;
    }

    std::cout << "Результирующий вектор С:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}