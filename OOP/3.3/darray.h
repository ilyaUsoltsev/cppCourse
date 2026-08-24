#pragma once

class DArray {
  enum {
    start_length_array = 10,
    resize_factor = 2,
    max_length_array = 100,
    value_error = 2123456789
  };

  class Item {
    DArray *array{nullptr};
    int index{-1};

  public:
    Item(DArray *arr, int idx) : array(arr), index(idx) {}
    // case when we want to assign a value to the array element
    // eg. arr[1] = 100;
    int operator=(int value) {
      if (index >= 0 && index < array->length) {
        array->data[index] = value;
      }
      // extend size, fill with zeroes
      else if (index >= array->length && index < array->capacity) {
        for (int i = array->length; i < index; ++i) {
          array->data[i] = 0;
        }
        array->data[index] = value;
        array->length = index + 1;
      }
      return value;
    }
    // eg. int value = arr[1];
    operator int() const {
      if (index >= 0 && index < array->length) {
        return array->data[index];
      }
      return value_error;
    }
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
  Item operator[](int index) { return Item(this, index); }

  ~DArray() { delete[] data; }

  int size() const { return length; }
  int capacity_ar() const { return capacity; }
  const int *get_data() const { return data; }

  const DArray &operator=(const DArray &other);

  void push_back(int value);

  int pop_back();
};
