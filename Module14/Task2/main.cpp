#include <iostream>

void printBoard(char board[3][3]) {
    std::cout << "  0 1 2\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j];
            if (j < 2) std::cout << "|";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "  -----\n";
    }
}

bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    return false;
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char currentPlayer = 'X';
    int movesLeft = 9;

    std::cout << "--==Игра Крестики-нолики!==--\n";
    std::cout << "Игроки по очереди вводят координаты клетки (строка и столбец).\n";

    while (movesLeft > 0) {
        printBoard(board);

        int row, col;
        std::cout << "Ход игрока " << currentPlayer << ". Введите строку и столбец (0-2): ";
        std::cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2) {
            std::cout << "Неверные координаты. Попробуйте снова.\n";
            continue;
        }
        if (board[row][col] != ' ') {
            std::cout << "Клетка уже занята. Попробуйте снова.\n";
            continue;
        }

        board[row][col] = currentPlayer;
        movesLeft--;

        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            std::cout << "Игрок " << currentPlayer << " победил!\n";
            return 0;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    printBoard(board);
    std::cout << "Ничья!\n";

    return 0;
}