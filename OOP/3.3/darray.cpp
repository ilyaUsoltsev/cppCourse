#include "darray.h"

void DArray::_resize_array(int size_new) {
  if (size_new <= capacity) {
    return;
  }

  while (capacity <= size_new) {
    capacity *= resize_factor;
    if (capacity >= max_length_array) {
      capacity = max_length_array;
      break;
    }
  }

  int *new_data = new int[capacity];
  for (int i = 0; i < length; ++i) {
    new_data[i] = data[i];
  }
  delete[] data;
  data = new_data;
}

const DArray &DArray::operator=(const DArray &other) {
  if (this == &other) {
    return *this;
  }

  delete[] data;

  length = other.length;
  capacity = other.capacity;
  data = new int[capacity];
  for (int i = 0; i < length; ++i) {
    data[i] = other.data[i];
  }

  return *this;
}

void DArray::push_back(int value) {
  if (length >= capacity) {
    _resize_array(capacity * resize_factor);
  }
  data[length++] = value;
}

int DArray::pop_back() {
  if (length == 0) {
    return value_error;
  }
  return data[--length];
}
