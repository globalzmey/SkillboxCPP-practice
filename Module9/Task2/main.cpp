#include <iostream>

int main() {
    std::string s;
    std::cin >> s;


    if (s == "") {
        std::cout << "No\n";
        return 0;
    }

    int n = s.length();
    bool hasDigit = false;
    bool hasDot = false;

    if (n == 1) {
        if (s[0] == '.' || (s[0] >= '0' && s[0] <= '9')) {
            hasDigit = (s[0] >= '0' && s[0] <= '9');
            std::cout << (hasDigit ? "Yes\n" : "No\n");
            return 0;
        } else {
            std::cout << "No\n";
            return 0;
        }
    }

    if (!(s[0] == '-' || s[0] == '.' || (s[0] >= '0' && s[0] <= '9'))) {
        std::cout << "No\n";
        return 0;
    }

    for (int i = 1; i < n; ++i) {
        if (s[i] == '.') {
            if (hasDot) {
                std::cout << "No\n";
                return 0;
            }
            hasDot = true;
        } else if (s[i] >= '0' && s[i] <= '9') {
            hasDigit = true;
        } else {
            std::cout << "No\n";
            return 0;
        }
    }

    if (s[0] == '-') {
        if (n == 1 || (s[1] != '.' && !(s[1] >= '0' && s[1] <= '9'))) {
            std::cout << "No\n";
            return 0;
        }
    }

    if (!hasDigit) {
        std::cout << "No\n";
        return 0;
    }

    std::cout << "Yes\n";
    
    return 0;
}