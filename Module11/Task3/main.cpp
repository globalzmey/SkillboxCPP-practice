#include <iostream>
#include <string>

bool isValidPart(std::string part) {
    if (part.length() == 0 || part.length() > 3) {
        return false;
    }

    if (part[0] == '0' && part.length() > 1) {
        return false;
    }

    int num = 0;
    for (int i = 0; i < part.length(); i++) {
        if (part[i] < '0' || part[i] > '9') {
            return false;
        }
        num = num * 10 + (part[i] - '0');
    }

    return num >= 0 && num <= 255;
}

bool isValidIP(std::string ip) {
    std::string part;
    int count = 0;
    
    for (int i = 0; i < ip.length(); i++) {
        if (ip[i] == '.') {
            if (!isValidPart(part)) {
                return false;
            }
            count++;
            part = "";
        } else {
            part += ip[i];
        }
    }

    if (!isValidPart(part)) {
        return false;
    }
    count++;

    return count == 4;
}

int main() {
    std::string ip;
    std::cout << "Input IP-address: ";
    std::cin >> ip;

    if (isValidIP(ip)) {
        std::cout << "Valid" << std::endl;
    } else {
        std::cout << "Invalid" << std::endl;
    }

    return 0;
}