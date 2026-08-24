#include <iostream>

// здесь объявляйте класс

class AbsoluteValue {
public:
  unsigned long value{0};

  AbsoluteValue() = default;
  AbsoluteValue(unsigned long v) : value(v) {
    if (v < 0) {
      this->value = -v;
    }
  }
  AbsoluteValue &operator=(const int &other) {
    this->value = other < 0 ? -other : other;
    return *this;
  }
};

int main(void) {
  // здесь продолжайте функцию main
  AbsoluteValue *ptr_abv = new AbsoluteValue();
  *ptr_abv = -512;

  AbsoluteValue v3 = -10;
  std::cout << "v3.value = " << v3.value << std::endl;

  // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и
  // должно идти непосредственно перед return 0 или перед освобождением
  // памяти)

  // здесь освобождайте память

  delete ptr_abv;
  return 0;
}
