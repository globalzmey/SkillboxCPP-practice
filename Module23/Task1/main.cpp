#include <iostream>

// Макросы-строки для дней недели
#define DAY_1 "Monday"
#define DAY_2 "Tuesday"
#define DAY_3 "Wednesday"
#define DAY_4 "Thursday"
#define DAY_5 "Friday"
#define DAY_6 "Saturday"
#define DAY_7 "Sunday"

// Макрос для получения названия дня недели
#define GET_DAY_NAME(num) DAY_##num

int main() {
    int dayNumber;
    std::cout << "Enter day number (1-7): ";
    std::cin >> dayNumber;

    switch (dayNumber) {
    case 1:
        std::cout << GET_DAY_NAME(1) << std::endl;
        break;
    case 2:
        std::cout << GET_DAY_NAME(2) << std::endl;
        break;
    case 3:
        std::cout << GET_DAY_NAME(3) << std::endl;
        break;
    case 4:
        std::cout << GET_DAY_NAME(4) << std::endl;
        break;
    case 5:
        std::cout << GET_DAY_NAME(5) << std::endl;
        break;
    case 6:
        std::cout << GET_DAY_NAME(6) << std::endl;
        break;
    case 7:
        std::cout << GET_DAY_NAME(7) << std::endl;
        break;
    default:
        std::cout << "Invalid day number!" << std::endl;
    }

    return 0;
}