#include <iostream>

class BottleWater {
  enum { max_volume = 320 }; // максимальный объем воды
  unsigned volume{0};        // объем воды в бутылке
public:
  BottleWater(unsigned volume = 0)
      : volume(volume > max_volume ? max_volume : volume) {}

  BottleWater operator+(const BottleWater &other) const {
    unsigned res = this->volume + other.volume;
    if (res > this->max_volume) {
      return this->max_volume;
    }
    return res;
  }

  unsigned get_volume() const { return volume; }
};

int main(void) {
  // здесь продолжайте функцию main
  BottleWater bw1(40), bw2(200);
  BottleWater res = bw1 + bw2; // здесь должен быть вызван оператор +

  // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно
  // идти непосредственно перед return 0 или перед освобождением памяти)

  return 0;
}
