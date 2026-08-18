#include <iostream>

class Point {
  static int MIN_COORD;
  static int MAX_COORD;

private:
  int x{0}, y{0};
  bool check_coord(int coord) {
    return (coord >= MIN_COORD && coord <= MAX_COORD);
  }

public:
  Point(int x = 0, int y = 0) {
    if (check_coord(x) && check_coord(y)) {
      this->x = x;
      this->y = y;
    } else {
      this->x = 0;
      this->y = 0;
    }
  }
  static void set_bounds(int left, int right) {
    if (left < right) {
      MIN_COORD = left;
      MAX_COORD = right;
    }
  }
  static void get_bounds(int &left, int &right) {
    left = MIN_COORD;
    right = MAX_COORD;
  }
  void set_coords(int x, int y) {
    if (check_coord(x) && check_coord(y)) {
      this->x = x;
      this->y = y;
    }
  }
  int get_x() { return x; }
  int get_y() { return y; }
};

int Point::MIN_COORD = 0;
int Point::MAX_COORD = 100;

// здесь объявляйте класс

int main(void) {
  // здесь продолжайте функцию main
  Point::set_bounds(-100, 100);
  int z, y;
  Point::get_bounds(z, y);
  Point pt(-5, 7);

  //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно
  // идти непосредственно перед return 0 или перед
  // освобождением памяти)

  return 0;
}
