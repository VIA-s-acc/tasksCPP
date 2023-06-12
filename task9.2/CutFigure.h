
#include "Figure.h"

class CutFigure : public Figure {
private:
    Figure* base;
    double cutArea;
public:
    CutFigure(Figure* f, double c);
    virtual double area() const;
};
