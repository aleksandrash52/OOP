#include "Rhombus.h"

Rhombus::Rhombus() : side(0), height(0) {}

Rhombus::Rhombus(double side, double height) : side(side), height(height) {}

std::pair<double, double> Rhombus::getGeometricCenter() const {
    return {side / 2, height / 2};
}

void Rhombus::print(std::ostream& os) const {
    os << "Rhombus: side=" << side << ", height=" << height;
}

void Rhombus::read(std::istream& is) {
    is >> side >> height;
}

double Rhombus::getArea() const {
    return side * height;
}

Rhombus* Rhombus::clone() const {
    return new Rhombus(*this);
}

bool Rhombus::operator==(const Figure& other) const {
    const Rhombus* otherRhombus = dynamic_cast<const Rhombus*>(&other);
    return otherRhombus && side == otherRhombus->side && height == otherRhombus->height;
}

Rhombus& Rhombus::operator=(const Figure& other) {
    const Rhombus* otherRhombus = dynamic_cast<const Rhombus*>(&other);
    if (otherRhombus) {
        side = otherRhombus->side;
        height = otherRhombus->height;
    }
    return *this;
}

Rhombus& Rhombus::operator=(Rhombus&& other) noexcept {
    if (this != &other) {
        side = other.side;
        height = other.height;
        other.side = 0;
        other.height = 0;
    }
    return *this;
}
