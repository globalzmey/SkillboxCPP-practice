#include <iostream>

int main() {

    int knives[2][6] = {{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}};
    int forks[2][6] = {{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}};
    int spoons[2][6] = {{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}};
    int plates[2][6] = {{2, 2, 2, 2, 2, 2}, {2, 2, 2, 2, 2, 2}};
    int chairs[2][6] = {{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}};

    spoons[0][0] += 1;
    spoons[0][1] += 1;
    plates[0][0] += 1;
    plates[0][1] += 1;

    chairs[0][4] += 1;
    spoons[1][2] -= 1;
    spoons[0][0] -= 1;
    spoons[1][2] += 1;
    plates[0][0] -= 1;

    std::cout << "Knives:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j) {
            std::cout << knives[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "Forks:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j) {
            std::cout << forks[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "Spoons:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j) {
            std::cout << spoons[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "Plates:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j) {
            std::cout << plates[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "Chairs:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j) {
            std::cout << chairs[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}