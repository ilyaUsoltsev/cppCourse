struct Point {
  short x{0}, y{0};
};

class Ellipse {
  Point sp, ep;

public:
  Ellipse(short x0, short y0, short x1, short y1) : sp{x0, y0}, ep{x1, y1} {}
  Ellipse(const Point &other) : sp{other} {}
  const Point &get_start() { return sp; }
  const Point &get_end() { return ep; }
};

int main() {
  Ellipse e(1, 2, 10, 20);

  return 0;
}
