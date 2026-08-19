#include <iostream>

// здесь объявляйте класс

class DataThree {
  static const int data_size = 3;
  static DataThree *instances[data_size];

  DataThree() {}

public:
  DataThree(const DataThree &) = delete;

  static DataThree *get_new_data() {
    for (int i = 0; i < data_size; ++i) {
      if (instances[i] == nullptr) {
        instances[i] = new DataThree();
        return instances[i];
      }
    }
    return instances[data_size -
                     1]; // возвращаем последний объект, если все заняты
  }
};

DataThree *DataThree::instances[DataThree::data_size] = {nullptr, nullptr,
                                                         nullptr};

int main(void) {
  // здесь продолжайте функцию main
  DataThree *ptr_dates[5];
  for (int i = 0; i < 5; ++i) {
    ptr_dates[i] = DataThree::get_new_data();
  }

  // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно
  // идти непосредственно перед return 0 или перед освобождением памяти)

  // здесь освобождайте память (если необходимо)

  return 0;
}
