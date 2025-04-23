#include <iostream>
#include <cmath>
#include <string>

struct Vector2D {
    double x;
    double y;
};

// Функция для сложения двух векторов
Vector2D add(const Vector2D &v1, const Vector2D &v2) {
    return {v1.x + v2.x, v1.y + v2.y};
}

// Функция для вычитания двух векторов
Vector2D subtract(const Vector2D &v1, const Vector2D &v2) {
    return {v1.x - v2.x, v1.y - v2.y};
}

// Функция для умножения вектора на скаляр
Vector2D scale(const Vector2D &v, double scalar) {
    return {v.x * scalar, v.y * scalar};
}

// Функция для нахождения длины вектора
double length(const Vector2D &v) {
    return std::sqrt(v.x * v.x + v.y * v.y);
}

// Функция для нормализации вектора
Vector2D normalize(const Vector2D &v) {
    double len = length(v);
    if (len == 0) {
        std::cerr << "Ошибка: Невозможно нормализовать нулевой вектор." << std::endl;
        return {0, 0};
    }
    return {v.x / len, v.y / len};
}

// Функция для ввода вектора
Vector2D inputVector() {
    Vector2D v;
    std::cout << "Введите координаты вектора (x y): ";
    std::cin >> v.x >> v.y;
    return v;
}

int main() {
    std::string operation;
    std::cout << "Введите команду (add, subtract, scale, length, normalize): ";
    std::cin >> operation;

    if (operation == "add") {
        Vector2D v1 = inputVector();
        Vector2D v2 = inputVector();
        Vector2D result = add(v1, v2);
        std::cout << "Результат сложения: (" << result.x << ", " << result.y << ")" << std::endl;
    } else if (operation == "subtract") {
        Vector2D v1 = inputVector();
        Vector2D v2 = inputVector();
        Vector2D result = subtract(v1, v2);
        std::cout << "Результат вычитания: (" << result.x << ", " << result.y << ")" << std::endl;
    } else if (operation == "scale") {
        Vector2D v = inputVector();
        double scalar;
        std::cout << "Введите скаляр: ";
        std::cin >> scalar;
        Vector2D result = scale(v, scalar);
        std::cout << "Результат умножения на скаляр: (" << result.x << ", " << result.y << ")" << std::endl;
    } else if (operation == "length") {
        Vector2D v = inputVector();
        double result = length(v);
        std::cout << "Длина вектора: " << result << std::endl;
    } else if (operation == "normalize") {
        Vector2D v = inputVector();
        Vector2D result = normalize(v);
        std::cout << "Нормализованный вектор: (" << result.x << ", " << result.y << ")" << std::endl;
    } else {
        std::cerr << "Ошибка: Неизвестная команда." << std::endl;
    }

    return 0;
}