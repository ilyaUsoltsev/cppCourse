#include <iostream>

// здесь объявляйте класс
class DeskTop {
private:
  static DeskTop *instance_ptr;

private:
  int width{0}, height{0};

  DeskTop(int w, int h) : width(w), height(h) {}

public:
  static DeskTop *get_instance(int w, int h) {
    if (instance_ptr == nullptr) {
      instance_ptr = new DeskTop(w, h);
    }
    return instance_ptr;
  }

  int get_width() { return width; }

  int get_height() { return height; }
};

DeskTop *DeskTop::instance_ptr = nullptr;

int main(void) {
  // здесь продолжайте функцию main
  DeskTop *ptr_desk = DeskTop::get_instance(500, 200);
  // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно
  // идти непосредственно перед return 0 или перед
  // освобождением памяти)

  // здесь освобождайте память (если необходимо)
  delete ptr_desk;
  return 0;
}
