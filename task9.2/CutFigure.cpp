#include "CutFigure.h"

CutFigure::CutFigure(Figure* f, double c) : base(f), cutArea(c) {}

double CutFigure::area() const {
    return base->area() - cutArea;
}
