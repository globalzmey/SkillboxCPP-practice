#include <iostream>
#include <string>

const int SIZE = 10;

bool isValidPlacement(bool field[SIZE][SIZE], int x1, int y1, int x2, int y2, int size) {
    if (x1 != x2 && y1 != y2) return false;

    int length;
    if (x1 == x2) {
        length = (y1 > y2) ? (y1 - y2 + 1) : (y2 - y1 + 1);
    } else {
        length = (x1 > x2) ? (x1 - x2 + 1) : (x2 - x1 + 1);
    }
    
    if (length != size) return false;

    int start_x = (x1 < x2) ? x1 : x2;
    int end_x = (x1 > x2) ? x1 : x2;
    int start_y = (y1 < y2) ? y1 : y2;
    int end_y = (y1 > y2) ? y1 : y2;

    for (int x = start_x; x <= end_x; ++x) {
        for (int y = start_y; y <= end_y; ++y) {
            if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || field[x][y]) {
                return false;
            }
        }
    }
    return true;
}

void placeShip(bool field[SIZE][SIZE], int size, int count, int player) {
    for (int i = 0; i < count; ++i) {
        int x1, y1, x2, y2;
        while (true) {
            std::cout << "Player " << player << ", enter ";
            if (size == 1) {
                std::cout << "position for 1-cell ship (x,y): ";
                std::string input;
                std::cin >> input;
                size_t comma = input.find(',');
                if (comma == std::string::npos) {
                    std::cout << "Invalid format. Use x,y.\n";
                    continue;
                }
                x1 = x2 = atoi(input.substr(0, comma).c_str());
                y1 = y2 = atoi(input.substr(comma+1).c_str());
            } else {
                std::cout << "start and end for " << size << "-cell ship (x1,y1-x2,y2): ";
                std::string input;
                std::cin >> input;
                size_t hyphen = input.find('-');
                if (hyphen == std::string::npos) {
                    std::cout << "Invalid format. Use x1,y1-x2,y2.\n";
                    continue;
                }
                std::string start = input.substr(0, hyphen);
                std::string end = input.substr(hyphen+1);
                size_t comma1 = start.find(','), comma2 = end.find(',');
                x1 = atoi(start.substr(0, comma1).c_str());
                y1 = atoi(start.substr(comma1+1).c_str());
                x2 = atoi(end.substr(0, comma2).c_str());
                y2 = atoi(end.substr(comma2+1).c_str());
            }
            
            if (isValidPlacement(field, x1, y1, x2, y2, size)) {
                int start_x = (x1 < x2) ? x1 : x2;
                int end_x = (x1 > x2) ? x1 : x2;
                int start_y = (y1 < y2) ? y1 : y2;
                int end_y = (y1 > y2) ? y1 : y2;
                
                for (int x = start_x; x <= end_x; ++x) {
                    for (int y = start_y; y <= end_y; ++y) {
                        field[x][y] = true;
                    }
                }
                break;
            } else {
                std::cout << "Invalid placement. Check coordinates, direction, and overlapping.\n";
            }
        }
    }
}

bool isGameOver(bool field[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (field[i][j]) return false;
        }
    }
    return true;
}

bool attackPlayer(bool field[SIZE][SIZE], int attacker) {
    int x, y;
    while (true) {
        std::cout << "Player " << attacker << ", enter attack coordinates (x,y): ";
        std::string input;
        std::cin >> input;
        size_t comma = input.find(',');
        if (comma == std::string::npos) {
            std::cout << "Invalid format. Use x,y.\n";
            continue;
        }
        x = atoi(input.substr(0, comma).c_str());
        y = atoi(input.substr(comma+1).c_str());
        
        if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
            std::cout << "Coordinates out of bounds.\n";
            continue;
        }
        if (field[x][y]) {
            std::cout << "Hit!\n";
            field[x][y] = false;
            return isGameOver(field);
        } else {
            std::cout << "Miss.\n";
            return false;
        }
    }
}

int main() {
    bool field_1[SIZE][SIZE] = {false}, field_2[SIZE][SIZE] = {false};

    std::cout << "Player 1, place your ships.\n";
    placeShip(field_1, 1, 4, 1);
    placeShip(field_1, 2, 3, 1);
    placeShip(field_1, 3, 2, 1);
    placeShip(field_1, 4, 1, 1);

    std::cout << "Player 2, place your ships.\n";
    placeShip(field_2, 1, 4, 2);
    placeShip(field_2, 2, 3, 2);
    placeShip(field_2, 3, 2, 2);
    placeShip(field_2, 4, 1, 2);

    // Game loop
    while (true) {
        if (attackPlayer(field_2, 1)) {
            std::cout << "Player 1 wins!\n";
            break;
        }
        if (attackPlayer(field_1, 2)) {
            std::cout << "Player 2 wins!\n";
            break;
        }
    }

    return 0;
}