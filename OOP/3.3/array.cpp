#include <iostream>
#include <string>

class Array {
  int *data{nullptr};
  size_t size{0};

public:
  Array() = default;

  Array(int *ar, size_t s) : size(s) { this->set_data(ar, size); }

  Array operator+(const Array &other) const {
    int new_size = this->size + other.size;
    int *new_data = new int[new_size];
    for (int i = 0; i < size; ++i) {
      new_data[i] = data[i];
    }
    for (int i = size; i < new_size; ++i) {
      new_data[i] = other.data[i - size];
    }
    return Array(new_data, new_size);
  }
  Array &operator=(const Array &other) {
    if (this == &other) // присваивание объекта самому себе
      return *this;

    size = other.size;

    delete[] data;
    data = new int[size];
    for (size_t i = 0; i < size; ++i)
      data[i] = other.data[i];

    return *this;
  }

  ~Array() { delete[] data; }
  void set_data(int *d, size_t length) {
    delete[] data;
    size = length;
    data = new int[size];

    for (size_t i = 0; i < size; ++i)
      data[i] = d[i];
  }

  int *get_data() { return data; }
  size_t get_size() const { return size; }
};

int main() {
  Array res_1;
  Array ar1, ar2, ar3;
  int arr1[] = {1, 2, 3};
  int arr2[] = {4, 5, 6, 7};
  int arr3[] = {8, 9, 10, 11, 12};

  res_1 = ar1 + ar2; // объединение значений массивов data (по порядку) в
  //       единый
  //                  // массив; size - итоговая длина результирующего массива
  //                  data

  //   Array res_2 = ar1 + ar2 + ar3;

  //   for (size_t i = 0; i < res_2.get_size(); ++i) {
  //     std::cout << res_2.get_data()[i] << " ";
  //   }
  //   std::cout << std::endl;

  return 0;
}
