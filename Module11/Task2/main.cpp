#include <iostream>
#include <string>

bool isValidCharacter(char c, bool isLocalPart) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
        return true;
    }
    if (c == '-' || c == '.') {
        return true;
    }
    if (isLocalPart) {
        std::string specialChars = "!#$%&'*+/=?^_`{|}~";
        for (char sc : specialChars) {
            if (c == sc) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::string email;
    std::cout << "Input email please: ";
    std::cin >> email;

    size_t atPos = 0;
    bool atFound = false;
    for (size_t i = 0; i < email.length(); ++i) {
        if (email[i] == '@') {
            atPos = i;
            atFound = true;
            break;
        }
    }

    if (!atFound || atPos == 0 || atPos >= 64 || email.length() - atPos - 1 > 63) {
        std::cout << "No\n";
        return 0;
    }

    if (atPos == 0 || email.length() - atPos - 1 == 0) {
        std::cout << "No\n";
        return 0;
    }

    if (email[0] == '.' || email[atPos - 1] == '.') {
        std::cout << "No\n";
        return 0;
    }
    for (size_t i = 0; i < atPos; ++i) {
        if (!isValidCharacter(email[i], true)) {
            std::cout << "No\n";
            return 0;
        }
        if (i > 0 && email[i] == '.' && email[i - 1] == '.') {
            std::cout << "No\n";
            return 0;
        }
    }

    if (email[atPos + 1] == '.' || email[email.length() - 1] == '.') {
        std::cout << "No\n";
        return 0;
    }
    for (size_t i = atPos + 1; i < email.length(); ++i) {
        if (!isValidCharacter(email[i], false)) {
            std::cout << "No\n";
            return 0;
        }
        if (i > atPos + 1 && email[i] == '.' && email[i - 1] == '.') {
            std::cout << "No\n";
            return 0;
        }
    }

    std::cout << "Yes\n";

    return 0;
}