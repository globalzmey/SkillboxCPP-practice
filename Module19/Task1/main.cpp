#include <iostream>
#include <string>
#include <fstream>

int main() {
    std::ifstream file("input.txt");
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open the file." << std::endl;
        return 1;
    }
    std::string word, targetWord;
    bool found = false;

    std::cout << "Enter the word to search for: ";
    std::cin >> targetWord;

    while (file >> word) {
        if (word == targetWord) {
            found = true;
            break;
        }
    }

    file.close();

    if (found) {
        std::cout << "The word '" << targetWord << "' was found in the file." << std::endl;
    } else {
        std::cout << "The word '" << targetWord << "' was not found in the file." << std::endl;
    }

    return 0;
}
