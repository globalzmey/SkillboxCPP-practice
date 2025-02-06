#include <iostream>
#include <cmath>

int main (){
    double fileSize, downLoadSpeed;

    std::cout << "Укажите размер файла для скачивания в мегабайтах: ";
    std::cin >> fileSize;
    while (fileSize <= 0) {
        std::cout << "Введите корректный размер файла: ";
        std::cin >> fileSize;
    }

    std::cout << "Какова скорость вашего соединения в MB/s?  ";
    std::cin >> downLoadSpeed;
    while (downLoadSpeed <= 0) {
        std::cout << "Введите корректную скорость соединения в MB/s? ";
        std::cin >> downLoadSpeed;
    }

    std::cout << "Вывод:\n";

    for (int i = 1; i <= ceil(fileSize / downLoadSpeed); i++) {
        double percent = floor(((downLoadSpeed * i) / fileSize) * 100);
        if (percent < 100) {
        std::cout << "Прошло " << i << " сек. Скачано " << downLoadSpeed * i << " из " << fileSize << " МБ (" <<  percent << "%).\n";
        } else {
        std::cout << "Прошло " << i << " сек. Скачано " << fileSize << " из " << fileSize << " МБ (100%).\n";
        }
    }

    return 0;
}
