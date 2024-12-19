#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Figure.h"

class Trapezoid : public Figure {
public:
    Trapezoid();
    Trapezoid(double a, double b, double h);

    std::pair<double, double> getGeometricCenter() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    double getArea() const override;

    Trapezoid* clone() const override;
    bool operator==(const Figure& other) const override;
    Trapezoid& operator=(const Figure& other) override;
    Trapezoid& operator=(Trapezoid&& other) noexcept override;

private:
    double a, b, h;
};

#endif 
