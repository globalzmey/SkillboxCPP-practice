#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;

    std::ifstream inputFile(filename, std::ios::binary);
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Could not open the file." << std::endl;
        return 1;
    }

    const size_t bufferSize = 4096;
    std::vector<char> buffer(bufferSize);

    while (inputFile)
    {
        inputFile.read(buffer.data(), bufferSize);
        std::streamsize bytesRead = inputFile.gcount();
        if (bytesRead <= 0)
        {
            break;
        }

        std::cout.write(buffer.data(), bytesRead);
    }

    inputFile.close();

    return 0;
}
