class Line {
  short x0{0};
  short y0{0};
  short x1{0};
  short y1{0};
  int color{0};

public:
  Line() = default;
  Line(short x0_, short y0_, short x1_, short y1_)
      : x0(x0_), y0(y0_), x1(x1_), y1(y1_) {}
  int get_color() const { return this->color; }
  void get_coords(short &x0_, short &y0_, short &x1_, short &y1_) const {
    x0_ = this->x0;
    y0_ = this->y0;
    x1_ = this->x1;
    y1_ = this->y1;
  }
  void set_coords(short x0_, short y0_, short x1_, short y1_) {
    this->x0 = x0_;
    this->y0 = y0_;
    this->x1 = x1_;
    this->y1 = y1_;
  }
  void set_color(int color_) { this->color = color_; }

  Line &operator=(const Line &other) {
    this->x0 = other.x0;
    this->y0 = other.y0;
    this->x1 = other.x1;
    this->y1 = other.y1;
    return *this;
  }

  Line operator+(const Line &other) const {
    return Line(this->x0 + other.x0, this->y0 + other.y0, this->x1 + other.x1,
                this->y1 + other.y1);
  }
  Line &operator+=(const Line &other) {
    this->x0 += other.x0;
    this->y0 += other.y0;
    this->x1 += other.x1;
    this->y1 += other.y1;
    return *this;
  }
  Line operator-(const Line &other) const {
    return Line(this->x0 - other.x0, this->y0 - other.y0, this->x1 - other.x1,
                this->y1 - other.y1);
  }
  Line &operator-=(const Line &other) {
    this->x0 -= other.x0;
    this->y0 -= other.y0;
    this->x1 -= other.x1;
    this->y1 -= other.y1;
    return *this;
  }
  Line operator*(const Line &other) const {
    return Line(this->x0 * other.x0, this->y0 * other.y0, this->x1 * other.x1,
                this->y1 * other.y1);
  }
  Line &operator*=(const Line &other) {
    this->x0 *= other.x0;
    this->y0 *= other.y0;
    this->x1 *= other.x1;
    this->y1 *= other.y1;
    return *this;
  }
};

int main() {
  Line ln_1, ln_2(1, 2, 3, 4);
  ln_1 = ln_2; // копирование только координат x0, y0, x1, y1 (поле color не
               // копируется)
  Line ln_new(1, 1, 2, 2);
  ln_new += ln_1; // суммирование только для координат для объекта ln_new (поле
                  // color без изменений)
  ln_1 -= ln_2;   // вычитание только для координат для объекта ln_1 (поле color
                  // без изменений)
  ln_new *= ln_2; // умножение только для координат для объекта ln_new (поле
                  // color без изменений)
  Line res =
      ln_new + ln_2; // сложение соответствующих координат объектов ln_new, ln_2
                     // и присваивание результата объекту res

  return 0;
}
