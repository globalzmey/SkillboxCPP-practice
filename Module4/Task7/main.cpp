#include <iostream>

int main() {
    int weekDay;

    std::cout << "Введите день недели (от 1 до 7): ";
    std::cin >> weekDay;
    if (weekDay == 1) {
        std::cout << "Меню сегодня (понедельник):\n";
        std::cout << "Боржч \nВедьмин студень \nГазированная глина\n";
    }
    else if (weekDay == 2) {
            std::cout << "Меню сегодня (вторник):\n";
            std::cout << "Харчо \nСалат «Оливье» \nБаварские колбаски с капустой \nМорс\n";
    }
    else if (weekDay == 3) {
            std::cout << "Меню сегодня (среда):\n";
            std::cout << "Меню вторника\n";
    }
    else if (weekDay == 4) {
            std::cout << "Меню сегодня (четверг):\n";
            std::cout << "Гороховый суп \nСалат «Цезарь» с креветками \nКуриная ножка с пюре \nМорс\n";
    }
    else if (weekDay == 5) {
            std::cout << "Меню сегодня (пятница):\n";
            std::cout << "Суп из гороха \nИ всё\n";
    }
    else if (weekDay == 6) {
            std::cout << "Меню сегодня (суббота):\n";
            std::cout << "Объедки рабочей недели\n";
    }
    else if (weekDay == 7) {
            std::cout << "Меню сегодня (воскресенье):\n";
            std::cout << "Всё, что не съели в субботу.\n";
    }
    else {
        std::cout << "Вы ввели неправильный день недели.\nBye.\n";
    }

    return 0;
}
