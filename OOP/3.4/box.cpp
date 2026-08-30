#include <iostream>
class Box3D {
private:
  short a{0}, b{0}, c{0};

  class Dimension {
  private:
    Box3D &box;
    int index;

  public:
    Dimension(Box3D &box, int index) : box(box), index(index) {}

    Dimension &operator=(short value) {
      if (value < 0) {
        return *this; // Ignore negative values
      }
      if (index == 0)
        box.a = value;
      else if (index == 1)
        box.b = value;
      else if (index == 2)
        box.c = value;

      return *this;
    }

    operator short() const {
      if (index == 0)
        return box.a;
      if (index == 1)
        return box.b;
      return box.c;
    }
  };

public:
  Box3D() = default;

  Box3D(short a, short b, short c) : a(a), b(b), c(c) {}

  void get_dims(short &a, short &b, short &c) {
    a = this->a;
    b = this->b;
    c = this->c;
  }

  void set_dims(short a, short b, short c) {
    this->a = a;
    this->b = b;
    this->c = c;
  }

  Dimension operator[](int index) { return Dimension(*this, index); }

  operator int() const { return a * b * c; }
};

int main() {
  Box3D box(1, 2, 3);

  box[0] = -10;
  box[1] = 20;
  box[2] = 30;

  short x = box[0]; // 10
  short y = box[1]; // 20
  short z = box[2]; // 30

  int volume = box; // 6000
  std::cout << "Dimensions: " << x << ", " << y << ", " << z << std::endl;
  std::cout << "Volume: " << volume << std::endl;
  return 0;
}
