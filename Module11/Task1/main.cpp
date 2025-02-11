#include <iostream>
#include <string>

std::string encrypt_caesar(std::string text, int K) {
    std::string encryptedText = "";

    for (char c : text) {
        if (c >= 'A' && c <= 'Z') {
            char base = 'A';
            char shiftedChar = (c - base + K) % 26 + base;

            encryptedText += shiftedChar;
        } else if (c >= 'a' && c <= 'z') {
            char base = 'a';
            char shiftedChar = (c - base + K) % 26 + base;

            encryptedText += shiftedChar;
            
        } else {
            encryptedText += c;
        }
            
    }

    return encryptedText;

}

int main() {
    std::string text;
    int K;

    std::cout << "Input text: ";
    std::getline(std::cin, text);
    std::cout << "Enter shift (K): ";
    std::cin >> K;

    std::string encryptedText = encrypt_caesar(text, K);

    std::cout << "Encrypted text: " << encryptedText << "\n";

    return 0;
}