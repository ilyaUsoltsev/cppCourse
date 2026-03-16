#include "Triangle.h"
#include <cmath>
#include <iostream>

template<typename T>
Triangle<T>::Triangle(const Point<T>& p1,
                      const Point<T>& p2,
                      const Point<T>& p3)
    : p1(p1), p2(p2), p3(p3) {}

template<typename T>
Point<T> Triangle<T>::getP1() const {
    return p1;
}

template<typename T>
Point<T> Triangle<T>::getP2() const {
    return p2;
}

template<typename T>
Point<T> Triangle<T>::getP3() const {
    return p3;
}

template<typename T>
T Triangle<T>::area() const {
    T a = std::sqrt(std::pow(p2.getX() - p1.getX(), 2) + std::pow(p2.getY() - p1.getY(), 2));
    T b = std::sqrt(std::pow(p3.getX() - p2.getX(), 2) + std::pow(p3.getY() - p2.getY(), 2));
    T c = std::sqrt(std::pow(p1.getX() - p3.getX(), 2) + std::pow(p1.getY() - p3.getY(), 2));       
    T s = (a + b + c) / 2;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}   

/* Explicit instantiation */
template class Triangle<int>;
template class Triangle<double>;
template class Triangle<float>;
