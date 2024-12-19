#include <iostream>
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "Array.h"

int main() {
    Array<std::shared_ptr<Figure<int>>> figures;

    // Пример добавления фигур
    figures.push_back(std::make_shared<Trapezoid<int>>(3, 4, 5));
    figures.push_back(std::make_shared<Rhombus<int>>(6, 7));
    figures.push_back(std::make_shared<Pentagon<int>>(8));

    // Вывод информации о фигурах
    for (const auto& figure : figures) {
        std::cout << *figure << std::endl;
        std::cout << "Geometric Center: (" << figure->getGeometricCenter().first << ", " << figure->getGeometricCenter().second << ")" << std::endl;
        std::cout << "Area: " << figure->getArea() << std::endl;
    }

    // Удаление фигуры по индексу
    figures.pop_back();

    // Вывод общей площади фигур
    double totalArea = 0;
    for (const auto& figure : figures) {
        totalArea += figure->getArea();
    }
    std::cout << "Total Area: " << totalArea << std::endl;

    return 0;
}
