#pragma once

#include "Point.h"

template<typename T>
class Triangle {
private:
    Point<T> p1;
    Point<T> p2;
    Point<T> p3;

public:
    Triangle(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3);

    Point<T> getP1() const;
    Point<T> getP2() const;
    Point<T> getP3() const;

    T area() const;
};
