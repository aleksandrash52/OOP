#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"

class Pentagon : public Figure {
public:
    Pentagon();
    Pentagon(double side);

    std::pair<double, double> getGeometricCenter() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    double getArea() const override;

    Pentagon* clone() const override;
    bool operator==(const Figure& other) const override;
    Pentagon& operator=(const Figure& other) override;
    Pentagon& operator=(Pentagon&& other) noexcept override;

private:
    double side;
};

#endif 
