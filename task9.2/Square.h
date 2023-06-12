
#include "Figure.h"

class Square : public Figure {
private:
    double side;
public:
    Square(double s);
    virtual double area() const ;
};
