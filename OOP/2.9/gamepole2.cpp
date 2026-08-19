#include <iostream>

// здесь объявляйте класс

class GamePole {
private:
  static GamePole *instance;
  GamePole() = default;
  GamePole(int rows, int cols) : rows(rows), cols(cols) {
    pole = new char[rows * cols];
  }
  int rows{0}, cols{0};
  char *pole{nullptr};

public:
  // = operator
  GamePole &operator=(const GamePole &other) = delete;
  GamePole(const GamePole &other) = delete;
  ~GamePole() { delete[] pole; }
  void set_item(int row, int col, char value) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
      return;
    }
    pole[row * cols + col] = value;
  }
  char get_item(int row, int col) const {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
      return '\0';
    }
    return pole[row * cols + col];
  }
  const char *get_pole() const { return pole; }
  void get_size(int &rows, int &cols) const {
    rows = this->rows;
    cols = this->cols;
  }
  static GamePole *init(int rows, int cols) {
    if (instance == nullptr) {
      instance = new GamePole(rows, cols);
    }
    return instance;
  }
};

GamePole *GamePole::instance = nullptr;

int main(void) {
  // здесь продолжайте функцию main
  GamePole *ptr_pl = GamePole::init(10, 7);
  ptr_pl->set_item(1, 1, '@');
  ptr_pl->set_item(4, 9, '#');
  ptr_pl->set_item(3, 2, '*');

  // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно
  // идти непосредственно перед return 0 или перед
  // освобождением памяти)

  return 0;
}
