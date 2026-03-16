#include <iostream>
#include "Triangle.h"

int main() {

    Point<double> a(120.0, 2.0);
    Point<double> b(13.0, 9.0);
    Point<double> c(33.0, -1.0);

    Triangle<double> t(a, b, c);

    std::cout << "Area: " << t.area() << std::endl;
}
