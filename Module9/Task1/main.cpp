#include <iostream>

int main() {
    char departureTime[6];
    char arrivalTime[6];

    std::cout << "Enter departure time (HH:MM): ";
    std::cin >> departureTime;

    if (departureTime[2] != ':' || 
        !(departureTime[0] >= '0' && departureTime[0] <= '2') ||
        !(departureTime[1] >= '0' && departureTime[1] <= '9' || (departureTime[0] == '2' && departureTime[1] <= '3')) ||
        !(departureTime[3] >= '0' && departureTime[3] <= '5') ||
        !(departureTime[4] >= '0' && departureTime[4] <= '9')) {
        std::cerr << "Incorrect time format!\n";
        return 1;
    }

    std::cout << "Enter arrival time (HH:MM): ";
    std::cin >> arrivalTime;

    if (arrivalTime[2] != ':' || 
        !(arrivalTime[0] >= '0' && arrivalTime[0] <= '2') ||
        !(arrivalTime[1] >= '0' && arrivalTime[1] <= '9' || (arrivalTime[0] == '2' && arrivalTime[1] <= '3')) ||
        !(arrivalTime[3] >= '0' && arrivalTime[3] <= '5') ||
        !(arrivalTime[4] >= '0' && arrivalTime[4] <= '9')) {
        std::cerr << "Incorrect time format!\n";
        return 1;
    }

    int depHours = (departureTime[0] - '0') * 10 + (departureTime[1] - '0');
    int depMinutes = (departureTime[3] - '0') * 10 + (departureTime[4] - '0');
    int arrHours = (arrivalTime[0] - '0') * 10 + (arrivalTime[1] - '0');
    int arrMinutes = (arrivalTime[3] - '0') * 10 + (arrivalTime[4] - '0');

    int depTotalMinutes = depHours * 60 + depMinutes;
    int arrTotalMinutes = arrHours * 60 + arrMinutes;

    if (arrTotalMinutes < depTotalMinutes) {
        arrTotalMinutes += 24 * 60;
    }

    int durationMinutes = arrTotalMinutes - depTotalMinutes;
    int durationHours = durationMinutes / 60;
    durationMinutes %= 60;

    std::cout << "The trip consisted of: " << durationHours << " h. " << durationMinutes << " min.\n";

    return 0;
}