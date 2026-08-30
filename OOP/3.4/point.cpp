#include <array>
#include <iostream>
#include <iterator>
#include <vector>

class PointND {
  short *coords{nullptr}; // координаты точки
  size_t dims{0};         // число координат
public:
  class Item {
  public:
    PointND *point{nullptr};
    int value{0};
    Item(PointND *obj, int v) : point(obj), value(v) {}
    int operator=(int rightValue) {
      point->coords[value] = rightValue;
      return rightValue;
    }
    operator int() { return point->coords[value]; }
  };
  PointND() = default;
  PointND(short *cds, size_t len) : dims(len) {
    coords = new short[dims];
    for (size_t i = 0; i < dims; ++i)
      coords[i] = cds[i];
  }
  PointND &operator=(const PointND &other) {
    if (this != &other) {
      short *new_coords = new short[dims];
      this->dims = other.dims;
      for (int i = 0; i < this->dims; ++i) {
        new_coords[i] = other.coords[i];
      }
      delete[] coords;
      this->coords = new_coords;
    }

    return *this;
  }

  Item operator[](int value) { return Item(this, value); }
  ~PointND() { delete[] coords; }
};

int main() {
  short coords[] = {1, 2, 3, 4, 5};
  PointND pt(coords, 5);
  PointND pt1(coords, 5);
  for (int i = 0; i < 5; ++i) {
    int val = pt[i];
    pt[i] = val;
    PointND pt2;
    pt2 = pt1;
  }
}
