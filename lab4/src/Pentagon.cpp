#include "Pentagon.h"
#include <cmath>

template <Scalar T>
Pentagon<T>::Pentagon(T side) : side(side) {}

template <Scalar T>
std::pair<T, T> Pentagon<T>::getGeometricCenter() const {
    return {side / 2, side / 2};
}

template <Scalar T>
void Pentagon<T>::print(std::ostream& os) const {
    os << "Pentagon: side=" << side;
}

template <Scalar T>
void Pentagon<T>::read(std::istream& is) {
    is >> side;
}

template <Scalar T>
double Pentagon<T>::getArea() const {
    return (5 * side * side * std::sqrt(5 + 2 * std::sqrt(5))) / 4;
}

template <Scalar T>
Pentagon<T>* Pentagon<T>::clone() const {
    return new Pentagon(*this);
}

template <Scalar T>
bool Pentagon<T>::operator==(const Figure<T>& other) const {
    const Pentagon<T>* otherPentagon = dynamic_cast<const Pentagon<T>*>(&other);
    return otherPentagon && side == otherPentagon->side;
}

template <Scalar T>
Pentagon<T>& Pentagon<T>::operator=(const Figure<T>& other) {
    const Pentagon<T>* otherPentagon = dynamic_cast<const Pentagon<T>*>(&other);
    if (otherPentagon) {
        side = otherPentagon->side;
    }
    return *this;
}

template <Scalar T>
Pentagon<T>& Pentagon<T>::operator=(Pentagon<T>&& other) noexcept {
    if (this != &other) {
        side = other.side;
        other.side = 0;
    }
    return *this;
}

template <Scalar T>
std::vector<std::unique_ptr<Point<T>>> Pentagon<T>::getVertices() const {
    std::vector<std::unique_ptr<Point<T>>> vertices;
    vertices.push_back(std::make_unique<Point<T>>(0, 0));
    vertices.push_back(std::make_unique<Point<T>>(side, 0));
    vertices.push_back(std::make_unique<Point<T>>(side / 2, side));
    vertices.push_back(std::make_unique<Point<T>>(0, side));
    vertices.push_back(std::make_unique<Point<T>>(-side / 2, side / 2));
    return vertices;
}

template class Pentagon<int>;
template class Pentagon<double>;
