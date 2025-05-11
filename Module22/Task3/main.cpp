#include <map>
#include <string>
#include <iostream>

bool isAnagram(const std::string &first, const std::string &second) {
    // Если длины строк разные, они не могут быть анаграммами
    if (first.length() != second.length()) {
        return false;
    }

    // Создаем карты для подсчета символов
    std::map<char, int> firstMap;
    std::map<char, int> secondMap;

    // Заполняем первую карту
    for (char c : first) {
        firstMap[c]++;
    }

    // Заполняем вторую карту
    for (char c : second) {
        secondMap[c]++;
    }

    // Сравниваем карты
    return firstMap == secondMap;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << isAnagram("лекарство", "стекловар") << std::endl;
    std::cout << isAnagram("hello", "world") << std::endl;
    std::cout << isAnagram("listen", "silent") << std::endl;
    return 0;
}