#include <iostream>

// здесь объявляйте класс

class Clock {
  unsigned tm{0};

public:
  unsigned get_time() const { return tm; }
  Clock(unsigned t = 0) : tm(t) {}

  Clock operator+(const Clock &other) { return Clock(tm + other.get_time()); }

  Clock &operator+=(unsigned value) {
    tm += value;
    return *this;
  }

  Clock &operator+=(const Clock &value) {
    tm += value.get_time();
    return *this;
  }

  Clock &operator-=(const Clock &value) {
    tm -= value.get_time();
    return *this;
  }

  unsigned operator++(int) {
    unsigned temp = tm;
    tm++;
    return temp;
  }
  unsigned operator++() { return ++tm; }
  unsigned operator--(int) {
    unsigned temp = tm;
    tm--;
    return temp;
  }
  unsigned operator--() { return --tm; }
};

int main(void) {
  // здесь продолжайте функцию main

  Clock clock_1(100), clock_2(430);

  Clock res = clock_1 + clock_2;

  // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно
  // идти непосредственно перед return 0 или перед освобождением памяти)

  return 0;
}
