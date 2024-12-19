#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Figure.h"

class Rhombus : public Figure {
public:
    Rhombus();
    Rhombus(double side, double height);

    std::pair<double, double> getGeometricCenter() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    double getArea() const override;

    Rhombus* clone() const override;
    bool operator==(const Figure& other) const override;
    Rhombus& operator=(const Figure& other) override;
    Rhombus& operator=(Rhombus&& other) noexcept override;

private:
    double side, height;
};

#endif 
