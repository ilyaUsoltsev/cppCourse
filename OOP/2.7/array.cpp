#include <iostream>

class Array {
  double *data{nullptr};
  size_t size{0};

private:
  Array() = default;
  Array(const Array &) = delete;

public:
  static Array *create(size_t length) {
    Array *arr = new Array();
    arr->size = length;
    arr->data = new double[length](); // инициализация нулями
    return arr;
  }

  static Array *create(double *d, size_t length) {
    Array *arr = new Array();
    arr->size = length;
    arr->data = new double[length];

    for (size_t i = 0; i < length; ++i)
      arr->data[i] = d[i];

    return arr;
  }

  ~Array() { delete[] data; }

  void set_data(double *d, size_t length) {
    delete[] data;
    size = length;
    data = new double[size];

    for (size_t i = 0; i < size; ++i)
      data[i] = d[i];
  }

  double *get_data() { return data; }
  size_t get_size() { return size; }
};
