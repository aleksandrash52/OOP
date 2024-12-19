#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Figure.h"

template <Scalar T>
class Trapezoid : public Figure<T> {
public:
    Trapezoid(T a, T b, T h);

    std::pair<T, T> getGeometricCenter() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    double getArea() const override;

    Trapezoid* clone() const override;
    bool operator==(const Figure<T>& other) const override;
    Trapezoid& operator=(const Figure<T>& other) override;
    Trapezoid& operator=(Trapezoid&& other) noexcept override;

    std::vector<std::unique_ptr<Point<T>>> getVertices() const override;

private:
    T a, b, h;
};

#endif 
