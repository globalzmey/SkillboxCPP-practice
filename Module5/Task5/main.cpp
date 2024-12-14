#include <iostream>

int main() {

    int A, B, C;
    int M, N, K;
    int tmp;

    std::cout << "Введите размеры первой коробки (A B C): ";
    std::cin >> A >> B >> C;

    std::cout << "Введите размеры второй коробки (M N K): ";
    std::cin >> M >> N >> K;

    std::cout << "-----<<<Рассчитываем>>>-----\n";

    //Сортируем строны коробки 1
    if (A > B) {
        tmp = A;
        A = B;
        B = tmp;
    }

    if (A > C) {
        tmp = A;
        A = C;
        C = tmp;
    }

    if (B > C) {
        tmp = B;
        B = C;
        C = tmp;
    }

    //Сортируем стороны коробки 2
    if (M > N) {
        tmp = M;
        M = N;
        N = tmp;
    }

    if (M > K) {
        tmp = M;
        M = K;
        K = tmp;
    }

    if (N > K) {
        tmp = N;
        N = K;
        K = tmp;
    }

    //Сравниваем стороны коробок 1 и 2
    if (A < M && B < N && C < K) {
        std::cout << "Первая коробка может поместиться во вторую.\n";
    }
    else {
        std::cout << "Первая коробка не может поместиться во вторую.\n";
    }

    return 0;

}
