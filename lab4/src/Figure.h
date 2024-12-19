#ifndef FIGURE_H
#define FIGURE_H

#include "Point.h"
#include <memory>
#include <vector>

template <Scalar T>
class Figure {
public:
    virtual ~Figure() = default;

    virtual std::pair<T, T> getGeometricCenter() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
    virtual double getArea() const = 0;

    virtual Figure* clone() const = 0;
    virtual bool operator==(const Figure& other) const = 0;
    virtual Figure& operator=(const Figure& other) = 0;
    virtual Figure& operator=(Figure&& other) noexcept = 0;

    virtual std::vector<std::unique_ptr<Point<T>>> getVertices() const = 0;
};

template <Scalar T>
std::ostream& operator<<(std::ostream& os, const Figure<T>& figure) {
    figure.print(os);
    return os;
}

template <Scalar T>
std::istream& operator>>(std::istream& is, Figure<T>& figure) {
    figure.read(is);
    return is;
}

#endif 
