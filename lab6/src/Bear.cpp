#include "Bear.h"

Bear::Bear(int x, int y, const std::string& name) {
    this->x = x;
    this->y = y;
    this->name = name;
}

std::string Bear::getType() const {
    return "Bear";
}

void Bear::print(std::ostream& os) const {
    os << "Bear: " << name << " at (" << x << ", " << y << ")";
}

void Bear::read(std::istream& is) {
    is >> x >> y >> name;
}

bool Bear::canAttack(const NPC& other) const {
    return other.getType() != "Bear";
}
