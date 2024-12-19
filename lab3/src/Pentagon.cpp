#include "Pentagon.h"

Pentagon::Pentagon() : side(0) {}

Pentagon::Pentagon(double side) : side(side) {}

std::pair<double, double> Pentagon::getGeometricCenter() const {
    return {side / 2, side / 2};
}

void Pentagon::print(std::ostream& os) const {
    os << "Pentagon: side=" << side;
}

void Pentagon::read(std::istream& is) {
    is >> side;
}

double Pentagon::getArea() const {
    return (5 * side * side * std::sqrt(5 + 2 * std::sqrt(5))) / 4;
}

Pentagon* Pentagon::clone() const {
    return new Pentagon(*this);
}

bool Pentagon::operator==(const Figure& other) const {
    const Pentagon* otherPentagon = dynamic_cast<const Pentagon*>(&other);
    return otherPentagon && side == otherPentagon->side;
}

Pentagon& Pentagon::operator=(const Figure& other) {
    const Pentagon* otherPentagon = dynamic_cast<const Pentagon*>(&other);
    if (otherPentagon) {
        side = otherPentagon->side;
    }
    return *this;
}

Pentagon& Pentagon::operator=(Pentagon&& other) noexcept {
    if (this != &other) {
        side = other.side;
        other.side = 0;
    }
    return *this;
}
