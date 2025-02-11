#include <iostream>
#include <string>

int main() {
    std::string ip;
    std::cout << "Input IP-address: ";
    std::cin >> ip;

    int numCount = 0;
    int currentNum = 0;
    int dotCount = 0;
    bool hasLeadingZero = false;
    bool isValid = true;

    for (size_t i = 0; i < ip.length(); ++i) {
        char c = ip[i];

        if (c == '.') {
            if (i == 0 || i == ip.length() - 1 || hasLeadingZero || currentNum > 255) {
                isValid = false;
                break;
            }
            numCount++;
            currentNum = 0;
            dotCount++;
            hasLeadingZero = false;
        } else if (c >= '0' && c <= '9') {
            if (currentNum == 0 && i > 0 && ip[i - 1] == '0') {
                hasLeadingZero = true;
            }
            currentNum = currentNum * 10 + (c - '0');
            if (currentNum > 255) {
                isValid = false;
                break;
            }
        } else {
            isValid = false;
            break;
        }
    }

    if (numCount != 3 || dotCount != 3 || currentNum > 255 || hasLeadingZero) {
        isValid = false;
    }

    if (isValid) {
        std::cout << "Valid\n";
    } else {
        std::cout << "Invalid\n";
    }

    return 0;
}