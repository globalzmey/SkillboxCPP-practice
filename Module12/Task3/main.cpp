#include <iostream>
#include <cassert>

float travelTime(float distance, float speed) {
    assert(speed > 0);

    return distance / speed;
}

int main() {
    float distance, speed;

    std::cout << "Введите расстояние (в км): ";
    std::cin >> distance;

    std::cout << "Введите скорость (в км/ч): ";
    std::cin >> speed;

    float time = travelTime(distance, speed);
    std::cout << "Время в пути: " << time << " часов" << std::endl;

    return 0;
}