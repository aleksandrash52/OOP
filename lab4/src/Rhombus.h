#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Figure.h"

template <Scalar T>
class Rhombus : public Figure<T> {
public:
    Rhombus(T side, T height);

    std::pair<T, T> getGeometricCenter() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    double getArea() const override;

    Rhombus* clone() const override;
    bool operator==(const Figure<T>& other) const override;
    Rhombus& operator=(const Figure<T>& other) override;
    Rhombus& operator=(Rhombus&& other) noexcept override;

    std::vector<std::unique_ptr<Point<T>>> getVertices() const override;

private:
    T side, height;
};

#endif 
