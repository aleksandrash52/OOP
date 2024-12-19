#include "Trapezoid.h"

template <Scalar T>
Trapezoid<T>::Trapezoid(T a, T b, T h) : a(a), b(b), h(h) {}

template <Scalar T>
std::pair<T, T> Trapezoid<T>::getGeometricCenter() const {
    return {(a + b) / 2, h / 2};
}

template <Scalar T>
void Trapezoid<T>::print(std::ostream& os) const {
    os << "Trapezoid: a=" << a << ", b=" << b << ", h=" << h;
}

template <Scalar T>
void Trapezoid<T>::read(std::istream& is) {
    is >> a >> b >> h;
}

template <Scalar T>
double Trapezoid<T>::getArea() const {
    return (a + b) * h / 2;
}

template <Scalar T>
Trapezoid<T>* Trapezoid<T>::clone() const {
    return new Trapezoid(*this);
}

template <Scalar T>
bool Trapezoid<T>::operator==(const Figure<T>& other) const {
    const Trapezoid<T>* otherTrapezoid = dynamic_cast<const Trapezoid<T>*>(&other);
    return otherTrapezoid && a == otherTrapezoid->a && b == otherTrapezoid->b && h == otherTrapezoid->h;
}

template <Scalar T>
Trapezoid<T>& Trapezoid<T>::operator=(const Figure<T>& other) {
    const Trapezoid<T>* otherTrapezoid = dynamic_cast<const Trapezoid<T>*>(&other);
    if (otherTrapezoid) {
        a = otherTrapezoid->a;
        b = otherTrapezoid->b;
        h = otherTrapezoid->h;
    }
    return *this;
}

template <Scalar T>
Trapezoid<T>& Trapezoid<T>::operator=(Trapezoid<T>&& other) noexcept {
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

template <Scalar T>
std::vector<std::unique_ptr<Point<T>>> Trapezoid<T>::getVertices() const {
    std::vector<std::unique_ptr<Point<T>>> vertices;
    vertices.push_back(std::make_unique<Point<T>>(0, 0));
    vertices.push_back(std::make_unique<Point<T>>(a, 0));
    vertices.push_back(std::make_unique<Point<T>>(b, h));
    vertices.push_back(std::make_unique<Point<T>>(0, h));
    return vertices;
}

template class Trapezoid<int>;
template class Trapezoid<double>;
