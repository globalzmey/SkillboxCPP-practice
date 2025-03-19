#include <iostream>
#include <string>
#include <cstring>

bool substr(const char* str, const char* sub) {
    if (!str || !sub) return false;

    if (strlen(str) < strlen(sub)) return false;
    
    for (int i = 0; str[i] != '\0'; i++) {
        int j = 0;
        while (sub[j] != '\0' && str[i + j] != '\0' && str[i + j] == sub[j]) {
            j++;
        }
        if (sub[j] == '\0') return true;
    }
    return false;
}

int main() {
    const char* a = "Hello world";
    const char* b = "wor";
    const char* c = "banana";
    std::cout << std::boolalpha << substr(a,b) << " " << substr(a,c) << std::endl;

    return 0;
}
