#include <iostream>

int main() {
    std::string s;
    std::cout << "Input string:\n";
    std::getline(std::cin, s);

    int wordCount = 0; 
    bool inWord = false;

    for (char c : s) {
        if (c != ' ' && c != '\t' && c != '\n') {
            if (!inWord) {
                wordCount++;
                inWord = true;
            }
        } else {
            inWord = false;
        }
    }

    std::cout << "Answer: " << wordCount << "\n";

    return 0;
}