#include "Figure.h"
class Circle : public Figure {
private:
    double radius;
public:
    Circle(double r);
    double get_radius();
    virtual double area() const ;
};
