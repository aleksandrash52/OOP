#include "Desman.h"

Desman::Desman(int x, int y, const std::string& name) {
    this->x = x;
    this->y = y;
    this->name = name;
}

std::string Desman::getType() const {
    return "Desman";
}

void Desman::print(std::ostream& os) const {
    os << "Desman: " << name << " at (" << x << ", " << y << ")";
}

void Desman::read(std::istream& is) {
    is >> x >> y >> name;
}

bool Desman::canAttack(const NPC& other) const {
    return other.getType() == "Bear";
}
