#pragma once

class DArray {
  enum {
    start_length_array = 10,
    resize_factor = 2,
    max_length_array = 100,
    value_error = 2123456789
  };

  int *data{nullptr};
  int length{0};
  int capacity{0};

  void _resize_array(int size_new);

public:
  DArray() : length(0), capacity(start_length_array) {
    data = new int[capacity];
  }
  DArray(const DArray &other) : length(other.length), capacity(other.capacity) {
    data = new int[capacity];
    for (int i = 0; i < length; ++i) {
      data[i] = other.data[i];
    }
  }
  ~DArray() { delete[] data; }

  int size() const { return length; }
  int capacity_ar() const { return capacity; }
  const int *get_data() const { return data; }

  const DArray &operator=(const DArray &other);

  void push_back(int value);

  int pop_back();
};
