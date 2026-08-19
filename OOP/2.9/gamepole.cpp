#include <iostream>

// здесь объявляйте класс

class GamePole {
private:
  int rows{0}, cols{0};
  char *pole{nullptr};

public:
  GamePole(int rows, int cols) : rows(rows), cols(cols) {
    pole = new char[rows * cols];
  }
  // = operator
  GamePole &operator=(const GamePole &other) {
    if (this == &other) {
      return *this;
    }
    delete[] pole;
    rows = other.rows;
    cols = other.cols;
    pole = new char[rows * cols];
    for (int i = 0; i < rows * cols; ++i) {
      pole[i] = other.pole[i];
    }
    return *this;
  }
  GamePole(const GamePole &other) : rows(other.rows), cols(other.cols) {
    pole = new char[rows * cols];
    for (int i = 0; i < rows * cols; ++i) {
      pole[i] = other.pole[i];
    }
  }
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
};

int main(void) {
  // здесь продолжайте функцию main
  GamePole pole(10, 7);
  pole.set_item(3, 5, '#');
  pole.set_item(4, 2, '*');
  pole.set_item(4, 4, '*');
  // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно
  // идти непосредственно перед return 0 или перед
  // освобождением памяти)

  return 0;
}
