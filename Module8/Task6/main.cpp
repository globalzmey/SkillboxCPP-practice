#include <iostream>
#include <cmath>

int main() {
    const double attenuation = 0.084;
    double startAplitude, endAplitude;
    int counter = 0;

    std::cout << "Введите начальную амплитуду (в см): ";
    std::cin >> startAplitude;
    while (startAplitude <= 0) {
        std::cout << "Ошибка. Введите положительное число: ";
        std::cin >> startAplitude;
    }
    std::cout << "Введите конечную амплитуду (в см) при которой маятник считается остановившимся: ";
    std::cin >> endAplitude;
    while (endAplitude <= 0 && endAplitude >= startAplitude) {
        std::cout << "Ошибка. Введите положительное число, меньшее начальной амплитуды: ";
        std::cin >> endAplitude;
    }
 
    while (startAplitude > endAplitude) {
        startAplitude *= (1 - attenuation);
        ++counter;        
    }

    std::cout << "Маятник считается остановившимся через " << counter << " колебаний.\n";

    return 0;
}