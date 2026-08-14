#include <iostream>

struct Point
{
    short x, y;
};

class Line {
    short x0, y0, x1, y1;
public:
    Line() : x0(0), y0(0), x1(0), y1(0) {
    }
    Line(short a, short b, short c, short d) : x0(a), y0(b), x1(c), y1(d) {
    }
    Line(Point sp, Point ep) : x0(sp.x), y0(sp.y), x1(ep.x), y1(ep.y) {
    }

    void set_coords(short a, short b, short c, short d) {
        this->x0 = a;
        this->y0 = b;
        this->x1 = c;
        this->y1 = d;
    }
    void set_coords(Point sp, Point ep) {
        this->x0 = sp.x;
        this->y0 = sp.y;
        this->x1 = ep.x;
        this->y1 = ep.y;
    }
    Point get_start() {
        Point sp;
        sp.x = this->x0;
        sp.y = this->y0;
        return sp;
    }
    Point get_end() {
        Point ep;
        ep.x = this->x1;
        ep.y = this->y1;
        return ep;
    }
    void print_coords() {
        std::cout << this->x0 << " " << this->y0 << " " << this->x1 << " " << this->y1 << " ";
    }

};

// здесь объявляйте класс Line

int main(void)
{
    Point sp, ep;
    short a, b, c, d;

    std::cin >> a >> b >> c >> d;
    std::cin >> sp.x >> sp.y >> ep.x >> ep.y;

    // здесь создавайте объекты класса Line
    Line* ptr_ln1 = new Line(a, b, c, d);
    Line* ptr_ln2 = new Line(sp, ep);

    ptr_ln1->print_coords();
    ptr_ln2->print_coords();

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память

    delete ptr_ln1;
    delete ptr_ln2;

    return 0;
}
