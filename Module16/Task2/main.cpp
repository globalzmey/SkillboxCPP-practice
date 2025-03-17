#include <iostream>
#include <string>

bool isNumeric(const std::string &str) {
    for (char c : str) {
        if (c < '0' || c > '9') {
            return false; 
        }
    }
    return true;
}

int main() {
    std::string intPart, fracPart;

    std::cout << "Enter the integer part: ";
    std::cin >> intPart;

    std::cout << "Enter the fractional part: ";
    std::cin >> fracPart;

    if (!isNumeric(intPart) || !isNumeric(fracPart)) {
        std::cerr << "Invalid input! Please enter numeric values only." << std::endl;
        return 1;
    }

    std::string numberStr = intPart + "." + fracPart;

    double number = std::stod(numberStr);

    std::cout << "The resulting number is: " << number << std::endl;

    return 0;
}