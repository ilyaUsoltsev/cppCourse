#pragma once

template<typename T>
class Point {
private:
    T x;
    T y;

public:
    Point(T x, T y);

    T getX() const;
    T getY() const;

    void setX(T value);
    void setY(T value);
};
