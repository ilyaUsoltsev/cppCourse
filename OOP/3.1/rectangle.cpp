#include <iostream>

// здесь объявляйте класс
class Rectangle {
private:
  int x0{0}, y0{0}, x1{0}, y1{0};

public:
  Rectangle(int x0, int y0, int x1, int y1) : x0{x0}, y0{y0}, x1{x1}, y1{y1} {}
  Rectangle() : x0{0}, y0{0}, x1{0}, y1{0} {}
  Rectangle operator+(const Rectangle &right) const {
    int new_x0 = min(this->x0, right.x0);
    int new_y0 = min(this->y0, right.y0);
    int new_x1 = max(this->x1, right.x1);
    int new_y1 = max(this->y1, right.y1);
    return Rectangle(new_x0, new_y0, new_x1, new_y1);
  }

  int min(int a, int b) const { return (a < b) ? a : b; }
  int max(int a, int b) const { return (a > b) ? a : b; }

  void get_coords(int &x0, int &y0, int &x1, int &y1) const {
    x0 = this->x0;
    y0 = this->y0;
    x1 = this->x1;
    y1 = this->y1;
  }
  void set_coords(int x0, int y0, int x1, int y1) {
    this->x0 = x0;
    this->y0 = y0;
    this->x1 = x1;
    this->y1 = y1;
  }
};

int main(void) {
  // здесь продолжайте функцию main
  // rect_1: -5, 0, 10, 12
  // rect_2: 1, -2, 7, 14
  Rectangle rect_1(-5, 0, 10, 12);
  Rectangle rect_2(1, -2, 7, 14);
  Rectangle res = rect_1 + rect_2;
  // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно
  // идти непосредственно перед return 0 или перед
  // освобождением памяти)

  return 0;
}
