#include <iostream>

class Rectangle {
  short x0{0}, y0{0}, x1{0}, y1{0};
  int border_color{0};
  int fill_color{255};

public:
  Rectangle() = default;
  Rectangle(short x0, short y0, short x1, short y1)
      : x0(x0), y0(y0), x1(x1), y1(y1) {}
  Rectangle &operator=(const Rectangle &other) {
    this->x0 = other.x0;
    this->x1 = other.x1;
    this->y0 = other.y0;
    this->y1 = other.y1;
    return *this;
  }
  int get_border_color() { return this->border_color; }
  int get_fill_color() { return this->fill_color; }
  void get_coords(short &x0, short &y0, short &x1, short &y1) {
    x0 = this->x0;
    x1 = this->x1;
    y0 = this->y0;
    y1 = this->y1;
  }
  void set_coords(short x0, short y0, short x1, short y1) {
    this->x0 = x0;
    this->x1 = x1;
    this->y0 = y0;
    this->y1 = y1;
  }
  void set_border_color(int color) { this->border_color = color; }
  void set_fill_color(int color) {
    this->fill_color = color;
  } // заносит переданное значение в поле fill_color
};
