#include "darray.h"
#include <iostream>

int main() {
  DArray arr;
  for (int i = 0; i < 15; ++i) {
    arr.push_back(i);
  }

  std::cout << "Size: " << arr.size() << ", Capacity: " << arr.capacity_ar()
            << std::endl;

  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr.get_data()[i] << " ";
  }
  std::cout << std::endl;

  for (int i = 0; i < 5; ++i) {
    arr.pop_back();
  }

  std::cout << "Size after pop: " << arr.size()
            << ", Capacity after pop: " << arr.capacity_ar() << std::endl;

  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr.get_data()[i] << " ";
  }
  std::cout << std::endl;

  // __ASSERT_TESTS__

  return 0;
}
