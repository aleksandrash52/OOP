#include "Trapezoid.h"

Trapezoid::Trapezoid() : a(0), b(0), h(0) {}

Trapezoid::Trapezoid(double a, double b, double h) : a(a), b(b), h(h) {}

std::pair<double, double> Trapezoid::getGeometricCenter() const {
    return {(a + b) / 2, h / 2};
}

void Trapezoid::print(std::ostream& os) const {
    os << "Trapezoid: a=" << a << ", b=" << b << ", h=" << h;
}

void Trapezoid::read(std::istream& is) {
    is >> a >> b >> h;
}

double Trapezoid::getArea() const {
    return (a + b) * h / 2;
}

Trapezoid* Trapezoid::clone() const {
    return new Trapezoid(*this);
}

bool Trapezoid::operator==(const Figure& other) const {
    const Trapezoid* otherTrapezoid = dynamic_cast<const Trapezoid*>(&other);
    return otherTrapezoid && a == otherTrapezoid->a && b == otherTrapezoid->b && h == otherTrapezoid->h;
}

Trapezoid& Trapezoid::operator=(const Figure& other) {
    const Trapezoid* otherTrapezoid = dynamic_cast<const Trapezoid*>(&other);
    if (otherTrapezoid) {
        a = otherTrapezoid->a;
        b = otherTrapezoid->b;
        h = otherTrapezoid->h;
    }
    return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& other) noexcept {
    if (this != &other) {
        a = other.a;
        b = other.b;
        h = other.h;
        other.a = 0;
        other.b = 0;
        other.h = 0;
    }
    return *this;
}
