#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>

class Figure {
public:
    virtual ~Figure() = default;

    virtual std::pair<double, double> getGeometricCenter() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
    virtual double getArea() const = 0;

    virtual Figure* clone() const = 0;
    virtual bool operator==(const Figure& other) const = 0;
    virtual Figure& operator=(const Figure& other) = 0;
    virtual Figure& operator=(Figure&& other) noexcept = 0;
};

std::ostream& operator<<(std::ostream& os, const Figure& figure);
std::istream& operator>>(std::istream& is, Figure& figure);

#endif 
