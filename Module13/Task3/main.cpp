#include <iostream>
#include <vector>

int main() {
    const int BUFFER_SIZE = 20;
    std::vector<int> db(BUFFER_SIZE);
    int head = 0;
    int count = 0;

    int input;
    while (true) {
        std::cout << "input number: ";
        std::cin >> input;

        if (input == -1) {
            std::cout << "output: ";
            for (int i = 0; i < count; ++i) {
                std::cout << db[(head + i) % BUFFER_SIZE] << " ";
            }
            std::cout << std::endl;
        } else {
            if (count < BUFFER_SIZE) {
                db[(head + count) % BUFFER_SIZE] = input;
                count++;
            } else {
                db[head] = input;
                head = (head + 1) % BUFFER_SIZE;
            }
        }
    }

    return 0;
}