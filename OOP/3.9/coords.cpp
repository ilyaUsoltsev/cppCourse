#include <iostream>

class CoordsND {
  enum { max_coords = 10 };
  int *coords{nullptr}; // массив значений координат
  int size{0};          // количество координат (не более max_coords)
public:
  CoordsND() = default;
  CoordsND(int *lst, int sz) {
    size = (sz > max_coords) ? max_coords : sz;

    coords = new int[size];
    for (int i = 0; i < size; ++i)
      coords[i] = lst[i];
  }

  CoordsND(const CoordsND &other) {
    size = other.size;
    coords = new int[size];
    for (int i = 0; i < size; ++i)
      coords[i] = other.coords[i];
  }

  CoordsND &operator=(const CoordsND &other) {
    if (this != &other) {
      delete[] coords; // освобождаем старую память
      size = other.size;
      coords = new int[size];
      for (int i = 0; i < size; ++i)
        coords[i] = other.coords[i];
    }
    return *this;
  }

  CoordsND(CoordsND &&other) noexcept {
    size = other.size;
    coords = other.coords;
    other.coords = nullptr; // предотвращаем двойное удаление
    other.size = 0;
  }

  CoordsND &operator=(CoordsND &&other) noexcept {
    if (this != &other) {
      delete[] coords; // освобождаем старую память
      size = other.size;
      coords = other.coords;
      other.coords = nullptr; // предотвращаем двойное удаление
      other.size = 0;
    }
    return *this;
  }

  ~CoordsND() { delete[] coords; }

  int *get_coords() { return coords; }
  int get_size() const { return size; }
};

int main() {
  CoordsND c0(new int[3]{1, 2, 3}, 3); // обычный конструктор
  // use all constructors and assignment operators
  int arr1[] = {1, 2, 3};
  CoordsND c1(arr1, 3); // обычный конструктор

  CoordsND c2 = c1;           // конструктор копирования
  CoordsND c3(std::move(c1)); // конструктор перемещения

  CoordsND c4(arr1, 3);
  c4 = c2; // оператор присваивания копированием
  c4 = c4; // самоприсваивание тест

  CoordsND c5(arr1, 3);
  c5 = std::move(c3); // оператор присваивания перемещением

  return 0;
}
