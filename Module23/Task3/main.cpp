#include <iostream>
#include <vector>

// Макрос для вызова функции над элементами массива с передачей индекса
#define CALL(func, array, index)       \
    {                                  \
        func(array[index], index + 1); \
    }

void analyzeOverfilledCarriage(int passengers, int carriageNumber) {
    const int optimalCapacity = 20;
    if (passengers > optimalCapacity) {
        std::cout << "Вагон " << carriageNumber << " переполнен " << passengers << " пассажирами." << std::endl;
    }
}

void analyzeEmptySeatsCarriage(int passengers, int carriageNumber) {
    const int optimalCapacity = 20;
    if (passengers < optimalCapacity) {
        std::cout << "В вагоне" << carriageNumber << " имеется " << (optimalCapacity - passengers) << " свободных мест." << std::endl;
    }
}

// Макрос для итерации по элементам массива
#define ITERATE(array, func) \
    CALL(func, array, 0);    \
    CALL(func, array, 1);    \
    CALL(func, array, 2);    \
    CALL(func, array, 3);    \
    CALL(func, array, 4);    \
    CALL(func, array, 5);    \
    CALL(func, array, 6);    \
    CALL(func, array, 7);    \
    CALL(func, array, 8);    \
    CALL(func, array, 9);

void countPassengers(int passengers, int &totalPassengers) {
    totalPassengers += passengers;
}

int main() {
    const int numCarriages = 10;
    std::vector<int> passengers(numCarriages);

    std::cout << "В каждом из вагонов может находиться до 20 пассажиров — это их оптимальное количество." << std::endl << std::endl;
    for (int i = 0; i < numCarriages; ++i) {
        std::cout << "Вагон " << i + 1 << ": ";
        std::cin >> passengers[i];
    }

    std::cout << "\nСводка по вагонам:" << std::endl;

    std::cout << "\nПереполненные вагоны:" << std::endl;
    ITERATE(passengers, analyzeOverfilledCarriage);

    std::cout << "\nВагоны с пустыми местами:" << std::endl;
    ITERATE(passengers, analyzeEmptySeatsCarriage);

    int totalPassengers = 0;
    for (int i = 0; i < numCarriages; ++i) {
        countPassengers(passengers[i], totalPassengers);
    }

    std::cout << "\nВсего пассажиров в составе: " << totalPassengers << std::endl;

    return 0;
}