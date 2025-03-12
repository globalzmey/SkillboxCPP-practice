#include <iostream>
#include <vector>

std::vector<int> allNumbers;
std::vector<int> topFive;

void insertSorted(int num) {
    if (topFive.size() < 5 || num < topFive.back()) {
        size_t insertPos = 0;
        while (insertPos < topFive.size() && topFive[insertPos] < num) {
            insertPos++;
        }

        topFive.insert(topFive.begin() + insertPos, num);

        if (topFive.size() > 5) {
            topFive.pop_back();
        }
    }
}

int main() {
    int num;

    while (true) {
        std::cin >> num;

        if (num == -2) {
            break;
        } else if (num == -1) {
            if (topFive.size() >= 5) {
                std::cout << "Вывод: " << topFive[4] << " (в отсортированном виде введённые числа выглядят так: {";
                std::vector<int> sortedNumbers = allNumbers;
                for (size_t i = 0; i < sortedNumbers.size(); ++i) {
                    for (size_t j = i + 1; j < sortedNumbers.size(); ++j) {
                        if (sortedNumbers[i] > sortedNumbers[j]) {
                            int temp = sortedNumbers[i];
                            sortedNumbers[i] = sortedNumbers[j];
                            sortedNumbers[j] = temp;
                        }
                    }
                }

                for (size_t i = 0; i < sortedNumbers.size(); ++i) {
                    std::cout << sortedNumbers[i];
                    if (i < sortedNumbers.size() - 1) {
                        std::cout << ", ";
                    }
                }
                std::cout << "})" << std::endl;
            } else {
                std::cout << "Недостаточно чисел для вывода пятого." << std::endl;
            }
        } else {
            allNumbers.push_back(num);

            insertSorted(num);
        }
    }

    return 0;
}