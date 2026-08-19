#include <iostream>

// здесь объявляйте класс

class BoxDims {
private:
  unsigned short dimention{0};
  unsigned *dims{nullptr};

public:
  BoxDims(unsigned short size_1) : dimention(1) {
    dims = new unsigned[dimention];
    dims[0] = size_1;
  }
  BoxDims(unsigned short size_1, unsigned short size_2) : dimention(2) {
    dims = new unsigned[dimention];
    dims[0] = size_1;
    dims[1] = size_2;
  }
  BoxDims(unsigned short size_1, unsigned short size_2, unsigned short size_3)
      : dimention(3) {
    dims = new unsigned[dimention];
    dims[0] = size_1;
    dims[1] = size_2;
    dims[2] = size_3;
  }
  // BoxDimss thing(ds, size_ds); // dimension = size_ds, dims = ds
  BoxDims(unsigned *ds, unsigned short size_ds) : dimention(size_ds) {
    dims = new unsigned[dimention];
    this->set_dims(ds);
  }
  BoxDims(const BoxDims &other) : dimention(other.dimention) {
    dims = new unsigned[dimention];
    this->set_dims(other.dims);
  }

  ~BoxDims() { delete[] dims; }
  void set_dims(unsigned *ds) {
    // задание значений габаритов (в массив dims); длина массива ds полагается
    // не меньше длины массива dims (данные заносятся в ранее созданный массив
    // dims, новый не создается; лишние значения отбрасываются)
    for (unsigned short i = 0; i < dimention; ++i) {
      dims[i] = ds[i];
    }
  }

  unsigned short get_dimension() const { return dimention; }
  const unsigned *get_dims() const { return dims; }
  unsigned get_volume() const {
    unsigned volume = 1;
    for (unsigned short i = 0; i < dimention; ++i) {
      volume *= dims[i];
    }
    return volume;
  }
};

int main(void) {
  // здесь продолжайте функцию main
  BoxDims box(3, 10, 5);
  BoxDims b1(122);
  // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно
  // идти непосредственно перед return 0 или перед освобождением памяти)

  return 0;
}
