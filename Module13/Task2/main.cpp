#include <iostream>
#include <vector>

int main() {
    std::vector<float> prices {2.5, 4.25, 3.0, 10.0};

    std::vector<int> items {1, 1, 0, 3};

    float totalCost = 0.0f;

    for (int itemIndex : items) {
        if (itemIndex >= 0 && itemIndex < static_cast<int>(prices.size())) {
            totalCost += prices[itemIndex];
        } else {
            std::cerr << "Warning: Item index " << itemIndex << " is out of bounds." << std::endl;
        }
    }

    std::cout << "Total cost: " << totalCost << std::endl;

    return 0;
}