#include "Bittern.h"

Bittern::Bittern(int x, int y, const std::string& name) {
    this->x = x;
    this->y = y;
    this->name = name;
}

std::string Bittern::getType() const {
    return "Bittern";
}

void Bittern::print(std::ostream& os) const {
    os << "Bittern: " << name << " at (" << x << ", " << y << ")";
}

void Bittern::read(std::istream& is) {
    is >> x >> y >> name;
}

bool Bittern::canAttack(const NPC& other) const {
    return false;
}
