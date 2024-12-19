#include <iostream>
#include <vector>
#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"

int main() {
    std::vector<Figure*> figures;

    figures.push_back(new Trapezoid(3, 4, 5));
    figures.push_back(new Rhombus(6, 7));
    figures.push_back(new Pentagon(8));

    for (const auto& figure : figures) {
        std::cout << *figure << std::endl;
        std::cout << "Geometric Center: (" << figure->getGeometricCenter().first << ", " << figure->getGeometricCenter().second << ")" << std::endl;
        std::cout << "Area: " << figure->getArea() << std::endl;
    }

    delete figures[1];
    figures.erase(figures.begin() + 1);

    double totalArea = 0;
    for (const auto& figure : figures) {
        totalArea += figure->getArea();
    }
    std::cout << "Total Area: " << totalArea << std::endl;

    for (auto& figure : figures) {
        delete figure;
    }

    return 0;
}
