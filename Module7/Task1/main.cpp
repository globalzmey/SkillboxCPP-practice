#include <iostream>

int main() {
	int grain = 100;

	std::cout << "Всего гречки было на начало подсчёта: " << grain << " кг.\n";

	for (int i = 1; grain > 0; i++) {
		grain -= 4;
		if (grain) {
			std::cout << "После " << i << " месяца у вас в запасе останется " << grain << " кг гречки.\n";
		} else {
			std::cout << "После " << i << " месяца гречка закончится.\n";
		}
	}

	return 0;
}
