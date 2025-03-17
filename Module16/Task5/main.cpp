#include <iostream>
#include <sstream>
#include <string>

enum switches {
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16
};

std::string formatTime(int hour) {
    int formattedHour = hour % 24;
    std::string time;
    if (formattedHour < 10) {
        time = "0" + std::to_string(formattedHour) + ":00";
    } else {
        time = std::to_string(formattedHour) + ":00";
    }
    return time;
}

int calculateColorTemperature(int hour) {
    if (hour >= 16 && hour < 20) {
        return 5000 - (hour - 16) * (5000 - 2700) / 4;
    }
    return 5000;
}

int main() {
    int switches_state = 0;
    int color_temperature = 5000;

    for (int hour = 0; hour < 48; ++hour) {
        std::cout << "Current time: " << formatTime(hour) << std::endl;

        std::string input;
        std::cout << "Temperature inside, temperature outside, movement, lights: ";
        std::getline(std::cin, input);

        std::stringstream ss(input);
        int temp_inside, temp_outside;
        std::string movement, lights;
        ss >> temp_inside >> temp_outside >> movement >> lights;

        if (temp_outside < 0 && !(switches_state & WATER_PIPE_HEATING)) {
            switches_state |= WATER_PIPE_HEATING;
            std::cout << "Water pipe heating ON!" << std::endl;
        } else if (temp_outside > 5 && (switches_state & WATER_PIPE_HEATING)) {
            switches_state &= ~WATER_PIPE_HEATING;
            std::cout << "Water pipe heating OFF!" << std::endl;
        }

        bool is_evening = (hour % 24 >= 16 || hour % 24 < 5);
        if (is_evening && movement == "yes" && !(switches_state & LIGHTS_OUTSIDE)) {
            switches_state |= LIGHTS_OUTSIDE;
            std::cout << "Outside lights ON!" << std::endl;
        } else if ((!is_evening || movement == "no") && (switches_state & LIGHTS_OUTSIDE)) {
            switches_state &= ~LIGHTS_OUTSIDE;
            std::cout << "Outside lights OFF!" << std::endl;
        }

        if (temp_inside < 22 && !(switches_state & HEATERS)) {
            switches_state |= HEATERS;
            std::cout << "Heaters ON!" << std::endl;
        } else if (temp_inside >= 25 && (switches_state & HEATERS)) {
            switches_state &= ~HEATERS;
            std::cout << "Heaters OFF!" << std::endl;
        }

        if (temp_inside >= 30 && !(switches_state & CONDITIONER)) {
            switches_state |= CONDITIONER;
            std::cout << "Conditioner ON!" << std::endl;
        } else if (temp_inside <= 25 && (switches_state & CONDITIONER)) {
            switches_state &= ~CONDITIONER;
            std::cout << "Conditioner OFF!" << std::endl;
        }

        if (lights == "on") {
            if (!(switches_state & LIGHTS_INSIDE)) {
                switches_state |= LIGHTS_INSIDE;
                std::cout << "Lights ON!" << std::endl;
            }
            int new_color_temperature = calculateColorTemperature(hour % 24);
            if (new_color_temperature != color_temperature) {
                color_temperature = new_color_temperature;
            }
        } else if (lights == "off" && (switches_state & LIGHTS_INSIDE)) {
            switches_state &= ~LIGHTS_INSIDE;
            std::cout << "Lights OFF!" << std::endl;
        }

        if (switches_state & LIGHTS_INSIDE) {
            std::cout << "Color temperature: " << color_temperature << "K" << std::endl;
        } else {
            std::cout << "Color temperature: Light is OFF" << std::endl;
        }

        std::cout << "-----------------------------" << std::endl;
    }

    return 0;
}