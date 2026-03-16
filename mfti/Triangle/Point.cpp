#include "Point.h"

template<typename T>
Point<T>::Point(T x, T y) : x(x), y(y) {}

template<typename T>
T Point<T>::getX() const {
    return x;
}

template<typename T>
T Point<T>::getY() const {
    return y;
}

template<typename T>
void Point<T>::setX(T value) {
    x = value;
}

template<typename T>
void Point<T>::setY(T value) {
    y = value;
}

/* Explicit instantiation */
template class Point<int>;
template class Point<double>;
template class Point<float>;
