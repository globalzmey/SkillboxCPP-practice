#include <iostream>
#include <cstdio>

int main() {
    double speed = 0.0;
    char speed_str[10];

    do {
        double delta;
        std::cout << "Speed delta: ";
        std::cin >> delta;

        speed += delta;
        if (speed > 150.0)
        {
            speed = 150.0;
        }
        else if (speed < 0.0)
        {
            speed = 0.0;
        }

        std::sprintf(speed_str, "%.1f", speed);

        std::cout << "Speed: " << speed_str << std::endl;

    } while (speed > 0.01);

    std::cout << "Car has stopped." << std::endl;
    return 0;
}