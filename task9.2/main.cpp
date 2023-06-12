#include <iostream>
#include "Circle.h"
#include "Square.h"
#include "CutFigure.h"
#include <vector>


d


int main() {
    Figure* c = new Circle(5);
    Figure* s = new Square(7);
    Figure* cf = new CutFigure(c, 5);
    Figure* inc = new InnerCircle(10,1,5);
    std::cout<< "InnerCircle " << inc->area(1)<<std::endl;
    std::cout << "Площадь окружности: " << c->area() << std::endl;
    std::cout << "Площадь квадрата: " << s->area() << std::endl;
    std::cout << "Площадь фигуры с вырезом: " << cf->area() << std::endl;

    delete c;
    delete s;
    delete cf;
    delete inc;
    return 0;
}