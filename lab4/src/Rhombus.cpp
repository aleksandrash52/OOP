#include "Rhombus.h"

template <Scalar T>
Rhombus<T>::Rhombus(T side, T height) : side(side), height(height) {}

template <Scalar T>
std::pair<T, T> Rhombus<T>::getGeometricCenter() const {
    return {side / 2, height / 2};
}

template <Scalar T>
void Rhombus<T>::print(std::ostream& os) const {
    os << "Rhombus: side=" << side << ", height=" << height;
}

template <Scalar T>
void Rhombus<T>::read(std::istream& is) {
    is >> side >> height;
}

template <Scalar T>
double Rhombus<T>::getArea() const {
    return side * height;
}

template <Scalar T>
Rhombus<T>* Rhombus<T>::clone() const {
    return new Rhombus(*this);
}

template <Scalar T>
bool Rhombus<T>::operator==(const Figure<T>& other) const {
    const Rhombus<T>* otherRhombus = dynamic_cast<const Rhombus<T>*>(&other);
    return otherRhombus && side == otherRhombus->side && height == otherRhombus->height;
}

template <Scalar T>
Rhombus<T>& Rhombus<T>::operator=(const Figure<T>& other) {
    const Rhombus<T>* otherRhombus = dynamic_cast<const Rhombus<T>*>(&other);
    if (otherRhombus) {
        side = otherRhombus->side;
        height = otherRhombus->height;
    }
    return *this;
}

template <Scalar T>
Rhombus<T>& Rhombus<T>::operator=(Rhombus<T>&& other) noexcept {
    if (this != &other) {
        side = other.side;
        height = other.height;
        other.side = 0;
        other.height = 0;
    }
    return *this;
}

template <Scalar T>
std::vector<std::unique_ptr<Point<T>>> Rhombus<T>::getVertices() const {
    std::vector<std::unique_ptr<Point<T>>> vertices;
    vertices.push_back(std::make_unique<Point<T>>(0, 0));
    vertices.push_back(std::make_unique<Point<T>>(side, 0));
    vertices.push_back(std::make_unique<Point<T>>(side / 2, height));
    vertices.push_back(std::make_unique<Point<T>>(0, height));
    return vertices;
}

template class Rhombus<int>;
template class Rhombus<double>;
