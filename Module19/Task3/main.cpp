#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void processPayments(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return;
    }

    int totalPayments = 0;
    int maxPayment = 0;
    std::string personWithMaxPayment;

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string name, date;
        int amount;

        std::string temp;
        while (ss >> temp && !isdigit(temp[0])) {
            name += temp + " ";
        }
        name.pop_back();

        amount = std::stoi(temp);
        ss >> date;

        totalPayments += amount;

        if (amount > maxPayment) {
            maxPayment = amount;
            personWithMaxPayment = name;
        }
    }

    file.close();

    std::cout << "Total amount of payments: " << totalPayments << std::endl;
    std::cout << "The person with the highest payout amount: "
              << personWithMaxPayment << " (" << maxPayment << ")" << std::endl;
}

int main() {
    std::string filename = "statement.txt";

    processPayments(filename);

    return 0;
}