#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream riverFile("river.txt");
    if (!riverFile.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл реки (river.txt)." << std::endl;
        return 1;
    }

    std::ofstream basketFile("basket.txt", std::ios::app);
    if (!basketFile.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл корзинки (basket.txt)." << std::endl;
        return 1;
    }

    std::string targetFish;
    std::cout << "Какую рыбу вы хотите ловить? ";
    std::cin >> targetFish;

    std::string fish;
    int caughtCount = 0;

    while (riverFile >> fish) {
        if (fish == targetFish) {
            basketFile << fish << "\n";
            ++caughtCount;
        }
    }

    riverFile.close();
    basketFile.close();

    std::cout << "Вы поймали " << caughtCount << " рыб за текущую ловлю." << std::endl;

    std::ifstream basketRead("basket.txt");
    int totalCaught = 0;
    while (basketRead >> fish) {
        ++totalCaught;
    }
    basketRead.close();

    std::cout << "Всего в корзинке сейчас " << totalCaught << " рыб." << std::endl;

    return 0;
}