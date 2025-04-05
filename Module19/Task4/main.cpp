#include <iostream>
#include <fstream>
#include <string>

bool isPngFile(const std::string& filePath) {
    if (filePath.length() < 4 || 
        filePath.substr(filePath.length() - 4) != ".png") {
        return false;
    }

    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open()) {
        return false;
    }

    unsigned char header[4];
    if (!file.read(reinterpret_cast<char*>(header), 4)) {
        file.close();
        return false;
    }
    file.close();

    return (header[0] == 0x89 &&
            header[1] == 'P' &&
            header[2] == 'N' &&
            header[3] == 'G');
}

int main() {
    std::string filePath;
    std::cout << "Enter file path: ";
    std::getline(std::cin, filePath);

    if (isPngFile(filePath)) {
        std::cout << "This is a PNG file!" << std::endl;
    } else {
        std::cout << "This is NOT a PNG file." << std::endl;
    }

    return 0;
}