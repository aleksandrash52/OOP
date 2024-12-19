#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"

template <Scalar T>
class Pentagon : public Figure<T> {
public:
    Pentagon(T side);

    std::pair<T, T> getGeometricCenter() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    double getArea() const override;

    Pentagon* clone() const override;
    bool operator==(const Figure<T>& other) const override;
    Pentagon& operator=(const Figure<T>& other) override;
    Pentagon& operator=(Pentagon&& other) noexcept override;

    std::vector<std::unique_ptr<Point<T>>> getVertices() const override;

private:
    T side;
};

#endif 
