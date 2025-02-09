#include <iostream>
int main() {
    std::string hiddenNumber, guessNumber;

    std::cout << "Input first number: ";
    std::cin >> hiddenNumber;

    std::cout << "Input second number: ";
    std::cin >> guessNumber;

    if (hiddenNumber.length() != 4 || guessNumber.length() != 4) {
        std::cout << "Both numbers must be four digits!\n";
        return 0;
    }

    int bulls = 0;
    int cows = 0;

    bool usedHidden[4] = {false};
    bool usedGuess[4] = {false};

    for (int i = 0; i < 4; ++i) {
        if (hiddenNumber[i] == guessNumber[i]) {
            bulls++;
            usedHidden[i] = true;
            usedGuess[i] = true;
        }
    }

    for (int i = 0; i < 4; ++i) {
        if (!usedGuess[i]) {
            for (int j = 0; j < 4; ++j) {
                if (!usedHidden[j] && hiddenNumber[j] == guessNumber[i]) {
                    cows++;
                    usedHidden[j] = true;
                    break;
                }
            }
        }
    }

    std::cout << "Bulls: " << bulls << ", cows: " << cows << "\n";

    return 0;
}