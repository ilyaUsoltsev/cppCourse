#include <cmath>
#include <iostream>

class Vector3D {

public:
  class Item {
    Vector3D *vector3d{nullptr};
    int value;

  public:
    Item(Vector3D *obj, int v) : vector3d(obj), value(v) {}

    operator int() {
      if (value == 0) {
        return vector3d->x;
      } else if (value == 1) {
        return vector3d->y;
      } else if (value == 2) {
        return vector3d->z;
      } else {
        return value;
      }
    }

    int operator=(int rightValue) {
      if (value == 0) {
        vector3d->x = rightValue;
      } else if (value == 1) {
        vector3d->y = rightValue;
      } else if (value == 2) {
        vector3d->z = rightValue;
      }
      return rightValue;
    }
  };

  int x{0}, y{0}, z{0};
  Vector3D(int a = 0, int b = 0, int c = 0) : x(a), y(b), z(c) {}

  Item operator[](int value) { return Item(this, value); }

  operator double() const {

    return std::sqrt(static_cast<double>(x) * x + static_cast<double>(y) * y +
                     static_cast<double>(z) * z);
  }

  void set_data(int a, int b, int c) {
    x = a;
    y = b;
    z = c;
  }
};

int main() {
  Vector3D v1, v2(1, 2, 3);
  v1[0] = 1;        // x = 5
  v1[1] = 2;        // y = 6
  v1[2] = 10;       // z = 7
  int a = v1[1];    // a = y; при v1[0] возвращается x, при v1[2] возвращается z
  double dist = v1; // возвращается евклидово расстояние радиус-вектора v2
  std::cout << "x = " << v1.x << std::endl;
  std::cout << "y = " << v1.y << std::endl;
  std::cout << "z = " << v1.z << std::endl;

  std::cout << "v1[0] = " << v1[0] << std::endl;
  std::cout << "v1[1] = " << v1[1] << std::endl;
  std::cout << "v1[2] = " << v1[2] << std::endl;

  double distance = static_cast<double>(v1);
  std::cout << "Distance = " << distance << std::endl;

  return 0;
}
