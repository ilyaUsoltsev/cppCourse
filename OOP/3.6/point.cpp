#include <iostream>

class PointND {
  short *coords{nullptr}; // координаты точки
  size_t dims{0};         // число координат

  class Item {
  public:
    PointND &point;
    size_t index;
    Item(PointND &pt, size_t idx) : point(pt), index(idx) {}
    short &operator=(short val) {
      if (index < point.dims)
        point.coords[index] = val;
      return val;
    }
    operator int() const {
      return (index < point.dims) ? point.coords[index] : 0;
    }
  };

public:
  PointND() = default;
  PointND(short *cds, size_t len) : dims(len) {
    coords = new short[dims];
    for (size_t i = 0; i < dims; ++i)
      coords[i] = cds[i];
  }
  PointND(const PointND &other) : dims(other.dims) {
    coords = new short[dims];
    for (size_t i = 0; i < dims; ++i)
      coords[i] = other.coords[i];
  }

  ~PointND() { delete[] coords; }

  Item operator[](size_t index) { return Item{*this, index}; }

  size_t get_dims() const { return dims; }

  PointND &operator=(const PointND &other) {
    if (this == &other)
      return *this;
    delete[] coords;
    dims = other.dims;
    coords = new short[dims];
    for (size_t i = 0; i < dims; ++i)
      coords[i] = other.coords[i];
    return *this;
  }

  PointND &operator++() {
    for (size_t i = 0; i < dims; ++i)
      ++coords[i];
    return *this;
  }

  PointND operator++(int) {
    PointND temp = *this;
    ++(*this);
    return temp;
  }

  PointND &operator--() {
    for (size_t i = 0; i < dims; ++i)
      --coords[i];
    return *this;
  }

  PointND operator--(int) {
    PointND temp = *this;
    --(*this);
    return temp;
  }

  PointND &operator+=(const PointND &other) {
    if (dims != other.get_dims())
      return *this;
    for (size_t i = 0; i < dims; ++i)
      coords[i] += other.coords[i];
    return *this;
  }

  PointND &operator-=(const PointND &other) {
    if (dims != other.get_dims())
      return *this;
    for (size_t i = 0; i < dims; ++i)
      coords[i] -= other.coords[i];
    return *this;
  }
};
