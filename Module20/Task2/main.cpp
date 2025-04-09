#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main() {
    int height, width;

    std::cout << "Введите высоту картины (в пикселях): ";
    std::cin >> height;
    std::cout << "Введите ширину картины (в пикселях): ";
    std::cin >> width;

    if (height <= 0 || width <= 0) {
        std::cerr << "Ошибка: Высота и ширина должны быть положительными числами." << std::endl;
        return 1;
    }

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::ofstream file("pic.txt");
    if (!file.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл." << std::endl;
        return 1;
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int pixel = std::rand() % 2;
            file << pixel;
        }
        file << "\n";
    }

    file.close();

    std::cout << "Бинарная картина сохранена в файле 'pic.txt'." << std::endl;

    return 0;
}