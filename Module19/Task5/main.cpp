#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<bool> played_sectors(13, false);
int current_sector = 1;
int viewers_score = 0;
int players_score = 0;

std::string readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + filename);
    }
    std::string content;
    std::getline(file, content);
    return content;
}

int getNextUnplayedSector(int sector) {
    int next = sector;
    while (played_sectors[next - 1]) {
        next = (next % 13) + 1;
    }
    return next;
}

void play() {
    while (viewers_score < 6 && players_score < 6) {
        std::cout << "\nСчет: Знатоки " << players_score << " - " << viewers_score << " Телезрители\n";
        std::cout << "Текущий сектор: " << current_sector << "\n";

        int offset;
        std::cout << "Введите смещение для вращения волчка: ";
        std::cin >> offset;

        int new_sector = ((current_sector + offset - 1) % 13) + 1;
        current_sector = getNextUnplayedSector(new_sector);
        
        std::cout << "Выпал сектор " << current_sector << "\n";
        played_sectors[current_sector - 1] = true;

        try {
            std::string question = readFile("questions/question_" + std::to_string(current_sector) + ".txt");
            std::cout << question << "\n";

            std::string player_answer;
            std::cout << "Ваш ответ: ";
            std::cin.ignore();
            std::getline(std::cin, player_answer);

            std::string correct_answer = readFile("answers/answer_" + std::to_string(current_sector) + ".txt");

            if (player_answer == correct_answer) {
                std::cout << "Правильно! Очко достается знатокам!\n";
                players_score++;
            } else {
                std::cout << "Неверно! Правильный ответ: " << correct_answer << "\n";
                std::cout << "Очко достается телезрителям!\n";
                viewers_score++;
            }
        } catch (const std::exception& e) {
            std::cerr << "Ошибка: " << e.what() << "\n";
            return;
        }
    }

    std::cout << "\nИгра окончена!\n";
    if (players_score >= 6) {
        std::cout << "Победили знатоки со счетом " << players_score << ":" << viewers_score << "!\n";
    } else {
        std::cout << "Победили телезрители со счетом " << viewers_score << ":" << players_score << "!\n";
    }
}

int main() {
    play();
    return 0;
}