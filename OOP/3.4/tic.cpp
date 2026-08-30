#include <iostream>

class TicTacToe {
  enum { size_pole = 3 };
  char pole[size_pole * size_pole]{0};

  class Row {
    TicTacToe &game;
    int row;

  public:
    Row(TicTacToe &game, int row) : game(game), row(row) {}

    char &operator[](int col) {
      static char zero = 0;

      if (row < 0 || row >= size_pole || col < 0 || col >= size_pole)
        return zero;

      return game.pole[row * size_pole + col];
    }
  };

public:
  const char *get_pole() const { return pole; }

  int get_size() const { return size_pole; }

  Row operator[](int row) { return Row(*this, row); }
};

int main(void) {
  // здесь продолжайте функцию main
  TicTacToe *ptr_game = new TicTacToe();
  (*ptr_game)[0][0] = 'x';
  (*ptr_game)[1][1] = 'x';
  (*ptr_game)[2][2] = 'x';

  // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно
  // идти непосредственно перед return 0 или перед
  // освобождением памяти)

  // здесь освобождайте память
  delete ptr_game;

  return 0;
}
