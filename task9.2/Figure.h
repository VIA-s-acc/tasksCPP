#pragma once
class Figure {
public:
    virtual double area() const = 0;
    virtual ~Figure() {}
    virtual double area(int n) { return area(); }
};
