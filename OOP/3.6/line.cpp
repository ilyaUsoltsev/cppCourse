class LineDouble {
  double x0{0}, y0{0}, x1{0}, y1{0};

public:
  void set_coords(double a, double b, double c, double d) {
    x0 = a;
    y0 = b;
    x1 = c;
    y1 = d;
  }

  void get_coords(double &a, double &b, double &c, double &d) const {
    a = x0;
    b = y0;
    c = x1;
    d = y1;
  }

  LineDouble() = default;
  LineDouble(double a, double b, double c, double d)
      : x0(a), y0(b), x1(c), y1(d) {};

  LineDouble operator+(const LineDouble &other) const {
    return LineDouble(x0 + other.x0, y0 + other.y0, x1 + other.x1,
                      y1 + other.y1);
  }

  LineDouble operator-=(const LineDouble &other) {
    x0 -= other.x0;
    y0 -= other.y0;
    x1 -= other.x1;
    y1 -= other.y1;
    return *this;
  }

  LineDouble operator+=(const LineDouble &other) {
    x0 += other.x0;
    y0 += other.y0;
    x1 += other.x1;
    y1 += other.y1;
    return *this;
  }

  LineDouble operator+=(double value) {
    x0 += value;
    y0 += value;
    x1 += value;
    y1 += value;
    return *this;
  }
  LineDouble operator-=(double value) {
    x0 -= value;
    y0 -= value;
    x1 -= value;
    y1 -= value;
    return *this;
  }

  LineDouble operator++() { // префиксный инкремент
    x0 += 0.1;
    y0 += 0.1;
    x1 += 0.1;
    y1 += 0.1;
    return *this;
  }

  LineDouble operator++(int) { // постфиксный инкремент
    LineDouble temp = *this;
    x0 += 0.1;
    y0 += 0.1;
    x1 += 0.1;
    y1 += 0.1;
    return temp;
  }

  LineDouble operator--() { // префиксный декремент
    x0 -= 0.1;
    y0 -= 0.1;
    x1 -= 0.1;
    y1 -= 0.1;
    return *this;
  }

  LineDouble operator--(int) { // постфиксный декремент
    LineDouble temp = *this;
    x0 -= 0.1;
    y0 -= 0.1;
    x1 -= 0.1;
    y1 -= 0.1;
    return temp;
  }
};
