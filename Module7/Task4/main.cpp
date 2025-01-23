#include <iostream>

int main() {
    int width, height;

    std::cout << "Введите ширину и высоту рамки: ";
    std::cin >> width >> height;

    if (width < 2 || height < 2) {
        std::cout << "Ширина и высота должны быть не меньше 2.\n" ;
        return 1;
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1) {
                if (j == 0 || j == width - 1) {
                    std::cout << "|";
                } else {
                    std::cout << "-";
                }
            } else {
                if (j == 0 || j == width - 1) {
                    std::cout << "|";
                } else {
                    std::cout << " ";
                }
            }
        }
        std::cout << "\n";
    }

    return 0;
}
