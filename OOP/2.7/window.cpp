
class Window {
private:
  static unsigned long total;
  int width, height, color;

public:
  // Конструктор без значений по умолчанию — Window w; невозможен
  Window(int w, int h, int c) : width(w), height(h), color(c) { ++total; }

  static unsigned long get_total() { return total; }

  void set_size(int w, int h) {
    width = w;
    height = h;
  }

  void get_size(int &w, int &h) {
    w = width;
    h = height;
  }

  int get_color() { return color; }
};

// Инициализация статического поля
unsigned long Window::total = 0;

int main(void) {
  // здесь продолжайте функцию main
  Window *ptr_wnd = new Window(200, 100, 255);

  // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно
  // идти непосредственно перед return 0 или перед освобождением памяти)

  // здесь освобождайте память
  delete ptr_wnd;

  return 0;
}
