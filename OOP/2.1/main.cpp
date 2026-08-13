#include <iostream>


class Point {
private:
    int x_{ 0 };
    int y_{ 0 };
    const int max_coord_{ 100 };
public:
    Point(int x = 0, int y = 0) : x_(x), y_(y) {
    }

    void print() const {
        std::cout << "Point(" << x_ << ", " << y_ << ")" << std::endl;
    }
};

int main() {
    Point p(3, 3);
    Point* ptr = new Point(13, 23);
    p.print();
    ptr->print();
    delete ptr;
    return 0;
}
