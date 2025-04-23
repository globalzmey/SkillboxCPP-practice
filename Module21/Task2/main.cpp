#include <iostream>
#include <vector>
#include <string>

// Перечисление типов комнат
enum RoomType {
    Bedroom,
    Kitchen,
    Bathroom,
    ChildrenRoom,
    LivingRoom
};

// Перечисление типов построек
enum BuildingType {
    House,
    Garage,
    Shed,
    Bathhouse
};

// Структура для комнаты
struct Room {
    RoomType type;
    double area;
};

// Структура для этажа
struct Floor {
    int number;
    double ceilingHeight;
    std::vector<Room> rooms;
};

// Структура для здания
struct Building {
    BuildingType type;
    double area;
    std::vector<Floor> floors;
    bool hasStove;
};

// Структура для участка
struct Plot {
    int number;
    double totalArea;
    std::vector<Building> buildings;
};

// Функция для ввода данных о комнате
Room inputRoom() {
    Room room;
    int roomType;
    std::cout << "Введите тип комнаты (0 - спальня, 1 - кухня, 2 - ванная, 3 - детская, 4 - гостиная): ";
    std::cin >> roomType;
    room.type = static_cast<RoomType>(roomType);

    std::cout << "Введите площадь комнаты: ";
    std::cin >> room.area;

    return room;
}

// Функция для ввода данных об этаже
Floor inputFloor(int floorNumber) {
    Floor floor;
    floor.number = floorNumber;

    std::cout << "Введите высоту потолка на этаже: ";
    std::cin >> floor.ceilingHeight;

    int roomCount;
    std::cout << "Введите количество комнат на этаже: ";
    std::cin >> roomCount;

    for (int i = 0; i < roomCount; ++i) {
        std::cout << "Комната " << i + 1 << ":" << std::endl;
        floor.rooms.push_back(inputRoom());
    }

    return floor;
}

// Функция для ввода данных о здании
Building inputBuilding() {
    Building building;
    int buildingType;
    std::cout << "Введите тип постройки (0 - дом, 1 - гараж, 2 - сарай, 3 - баня): ";
    std::cin >> buildingType;
    building.type = static_cast<BuildingType>(buildingType);

    std::cout << "Введите площадь постройки: ";
    std::cin >> building.area;

    if (building.type == House || building.type == Bathhouse) {
        std::cout << "Есть ли печь? (1 - да, 0 - нет): ";
        std::cin >> building.hasStove;
    }

    if (building.type == House) {
        int floorCount;
        std::cout << "Введите количество этажей в доме: ";
        std::cin >> floorCount;

        for (int i = 0; i < floorCount; ++i) {
            std::cout << "Этаж " << i + 1 << ":" << std::endl;
            building.floors.push_back(inputFloor(i + 1));
        }
    }

    return building;
}

// Функция для ввода данных об участке
Plot inputPlot(int plotNumber) {
    Plot plot;
    plot.number = plotNumber;

    std::cout << "Введите общую площадь участка: ";
    std::cin >> plot.totalArea;

    int buildingCount;
    std::cout << "Введите количество построек на участке: ";
    std::cin >> buildingCount;

    for (int i = 0; i < buildingCount; ++i) {
        std::cout << "Постройка " << i + 1 << ":" << std::endl;
        plot.buildings.push_back(inputBuilding());
    }

    return plot;
}

// Функция для расчёта процента земли, занятой постройками
double calculateOccupiedPercentage(const std::vector<Plot> &plots) {
    double totalLandArea = 0.0;
    double totalBuildingArea = 0.0;

    for (const auto &plot : plots) {
        totalLandArea += plot.totalArea;
        for (const auto &building : plot.buildings) {
            totalBuildingArea += building.area;
        }
    }

    return (totalBuildingArea / totalLandArea) * 100.0;
}

int main() {
    int plotCount;
    std::cout << "Введите количество участков в посёлке: ";
    std::cin >> plotCount;

    std::vector<Plot> plots;

    for (int i = 0; i < plotCount; ++i) {
        std::cout << "Участок " << i + 1 << ":" << std::endl;
        plots.push_back(inputPlot(i + 1));
    }

    double occupiedPercentage = calculateOccupiedPercentage(plots);
    std::cout << "Процент земли, занятой постройками: " << occupiedPercentage << "%" << std::endl;

    return 0;
}