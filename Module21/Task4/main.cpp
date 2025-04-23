#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

const int MAP_SIZE = 20;

struct Character {
    std::string name;
    int health;
    int armor;
    int damage;
    int x, y;
};

int getRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Проверка, свободна ли клетка
bool isCellFree(const std::vector<Character> &characters, int x, int y) {
    for (const auto &c : characters){
        if (c.x == x && c.y == y && c.health > 0)
            return false;
    }
    return true;
}

// Генерация случайных координат
void generateRandomPosition(std::vector<Character> &characters, int &x, int &y) {
    do {
        x = getRandom(0, MAP_SIZE - 1);
        y = getRandom(0, MAP_SIZE - 1);
    } while (!isCellFree(characters, x, y));
}

// Создание противников
std::vector<Character> createEnemies(int count) {
    std::vector<Character> enemies;
    for (int i = 1; i <= count; ++i) {
        Character enemy;
        enemy.name = "Enemy #" + std::to_string(i);
        enemy.health = getRandom(50, 150);
        enemy.armor = getRandom(0, 50);
        enemy.damage = getRandom(15, 30);
        generateRandomPosition(enemies, enemy.x, enemy.y);
        enemies.push_back(enemy);
    }
    return enemies;
}

// Отображение карты
void displayMap(const Character &player, const std::vector<Character> &enemies) {
    for (int y = 0; y < MAP_SIZE; ++y) {
        for (int x = 0; x < MAP_SIZE; ++x){
            bool isPlayer = (player.x == x && player.y == y);
            bool isEnemy = false;
            for (const auto &enemy : enemies) {
                if (enemy.x == x && enemy.y == y && enemy.health > 0) {
                    isEnemy = true;
                    break;
                }
            }
            if (isPlayer) {
                std::cout << "P ";
            } else if (isEnemy) {
                std::cout << "E ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << "\n";
    }
}

// Расчёт урона
void applyDamage(Character &attacker, Character &defender) {
    int damage = attacker.damage;
    if (defender.armor > 0) {
        if (damage <= defender.armor) {
            defender.armor -= damage;
        } else {
            int remainingDamage = damage - defender.armor;
            defender.armor = 0;
            defender.health -= remainingDamage;
        }
    } else {
        defender.health -= damage;
    }
    if (defender.health < 0)
        defender.health = 0;
}

// Перемещение противников
void moveEnemies(std::vector<Character> &enemies, const Character &player) {
    for (auto &enemy : enemies) {
        if (enemy.health <= 0)
            continue;
        int dx = getRandom(-1, 1);
        int dy = getRandom(-1, 1);
        int newX = enemy.x + dx;
        int newY = enemy.y + dy;
        if (newX >= 0 && newX < MAP_SIZE && newY >= 0 && newY < MAP_SIZE &&
            !(newX == player.x && newY == player.y)) {
            enemy.x = newX;
            enemy.y = newY;
        }
    }
}

// Сохранение игры
void saveGame(const Character &player, const std::vector<Character> &enemies) {
    std::ofstream file("save.bin", std::ios::binary);
    if (!file) {
        std::cerr << "Ошибка при сохранении игры.\n";
        return;
    }

    // Сохраняем игрока
    int nameLength = player.name.size();
    file.write(reinterpret_cast<const char *>(&nameLength), sizeof(nameLength)); // Длина имени
    file.write(player.name.c_str(), nameLength);                                 // Содержимое имени
    file.write(reinterpret_cast<const char *>(&player.health), sizeof(player.health));
    file.write(reinterpret_cast<const char *>(&player.armor), sizeof(player.armor));
    file.write(reinterpret_cast<const char *>(&player.damage), sizeof(player.damage));
    file.write(reinterpret_cast<const char *>(&player.x), sizeof(player.x));
    file.write(reinterpret_cast<const char *>(&player.y), sizeof(player.y));

    // Сохраняем противников
    int enemyCount = enemies.size();
    file.write(reinterpret_cast<const char *>(&enemyCount), sizeof(enemyCount));
    for (const auto &enemy : enemies) {
        nameLength = enemy.name.size();
        file.write(reinterpret_cast<const char *>(&nameLength), sizeof(nameLength)); // Длина имени
        file.write(enemy.name.c_str(), nameLength);                                  // Содержимое имени
        file.write(reinterpret_cast<const char *>(&enemy.health), sizeof(enemy.health));
        file.write(reinterpret_cast<const char *>(&enemy.armor), sizeof(enemy.armor));
        file.write(reinterpret_cast<const char *>(&enemy.damage), sizeof(enemy.damage));
        file.write(reinterpret_cast<const char *>(&enemy.x), sizeof(enemy.x));
        file.write(reinterpret_cast<const char *>(&enemy.y), sizeof(enemy.y));
    }

    std::cout << "Игра успешно сохранена.\n";
}

// Загрузка игры
bool loadGame(Character &player, std::vector<Character> &enemies) {
    std::ifstream file("save.bin", std::ios::binary);
    if (!file) {
        std::cerr << "Файл сохранения не найден.\n";
        return false;
    }

    // Загружаем игрока
    int nameLength;
    file.read(reinterpret_cast<char *>(&nameLength), sizeof(nameLength)); // Длина имени
    player.name.resize(nameLength);
    file.read(&player.name[0], nameLength); // Содержимое имени
    file.read(reinterpret_cast<char *>(&player.health), sizeof(player.health));
    file.read(reinterpret_cast<char *>(&player.armor), sizeof(player.armor));
    file.read(reinterpret_cast<char *>(&player.damage), sizeof(player.damage));
    file.read(reinterpret_cast<char *>(&player.x), sizeof(player.x));
    file.read(reinterpret_cast<char *>(&player.y), sizeof(player.y));

    // Загружаем противников
    int enemyCount;
    file.read(reinterpret_cast<char *>(&enemyCount), sizeof(enemyCount));
    enemies.clear();
    for (int i = 0; i < enemyCount; ++i) {
        Character enemy;
        file.read(reinterpret_cast<char *>(&nameLength), sizeof(nameLength)); // Длина имени
        enemy.name.resize(nameLength);
        file.read(&enemy.name[0], nameLength); // Содержимое имени
        file.read(reinterpret_cast<char *>(&enemy.health), sizeof(enemy.health));
        file.read(reinterpret_cast<char *>(&enemy.armor), sizeof(enemy.armor));
        file.read(reinterpret_cast<char *>(&enemy.damage), sizeof(enemy.damage));
        file.read(reinterpret_cast<char *>(&enemy.x), sizeof(enemy.x));
        file.read(reinterpret_cast<char *>(&enemy.y), sizeof(enemy.y));
        enemies.push_back(enemy);
    }

    std::cout << "Игра успешно загружена.\n";
    return true;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Character player;
    std::cout << "Введите имя игрока: ";
    std::cin >> player.name;
    std::cout << "Введите здоровье игрока: ";
    std::cin >> player.health;
    std::cout << "Введите броню игрока: ";
    std::cin >> player.armor;
    std::cout << "Введите урон игрока: ";
    std::cin >> player.damage;

    std::vector<Character> enemies = createEnemies(5);
    generateRandomPosition(enemies, player.x, player.y);

    while (true) {
        displayMap(player, enemies);

        // Проверка завершения игры
        bool allEnemiesDead = true;
        for (const auto &enemy : enemies) {
            if (enemy.health > 0) {
                allEnemiesDead = false;
                break;
            }
        }
        if (allEnemiesDead) {
            std::cout << "Вы победили всех противников!\n";
            break;
        }
        if (player.health <= 0){
            std::cout << "Вы проиграли.\n";
            break;
        }

        std::cout << "Введите команду (L, R, U, D, save, load, exit): ";
        std::string command;
        std::cin >> command;

        if (command == "save") {
            saveGame(player, enemies);
            continue;
        } else if (command == "load") {
            if (!loadGame(player, enemies))
                continue;
            continue;
        } else if (command == "exit") {
            std::cout << "Выход из игры.\n";
            break;
        } else if (command != "L" && command != "R" && command != "U" && command != "D") {
            std::cout << "Неверная команда. Попробуйте снова.\n";
            continue;
        }

        int newX = player.x, newY = player.y;
        if (command == "L")
            newX--;
        else if (command == "R")
            newX++;
        else if (command == "U")
            newY--;
        else if (command == "D")
            newY++;

        if (newX < 0 || newX >= MAP_SIZE || newY < 0 || newY >= MAP_SIZE){
            std::cout << "Невозможно выйти за пределы карты.\n";
            continue;
        }

        // Проверка на столкновение с противником
        bool attacked = false;
        for (auto &enemy : enemies) {
            if (enemy.x == newX && enemy.y == newY && enemy.health > 0){
                applyDamage(player, enemy);
                std::cout << "Вы атаковали " << enemy.name << "! Его здоровье: " << enemy.health << "\n";
                attacked = true;
                break;
            }
        }

        if (!attacked) {
            player.x = newX;
            player.y = newY;
        }

        moveEnemies(enemies, player);

        // Проверка атаки противников на игрока
        for (auto &enemy : enemies){
            if (enemy.x == player.x && enemy.y == player.y && enemy.health > 0) {
                applyDamage(enemy, player);
                std::cout << enemy.name << " атаковал вас! Ваше здоровье: " << player.health << "\n";
                break;
            }
        }
    }

    return 0;
}