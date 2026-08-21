#include <iostream>

// здесь объявляйте класс

enum type_filter { flt_aragon = 1, flt_calcium = 2 };

class FilterWater {
  type_filter type;
  unsigned date;
  unsigned short volume;

public:
  FilterWater(type_filter t, unsigned d, unsigned short v)
      : type(t), date(d), volume(v) {}

  friend type_filter get_type_filter(const FilterWater &flt);
  friend unsigned get_date_filter(const FilterWater &flt);
  friend unsigned short get_volume_filter(const FilterWater &flt);
};

type_filter get_type_filter(const FilterWater &flt) { return flt.type; }

unsigned get_date_filter(const FilterWater &flt) { return flt.date; }

unsigned short get_volume_filter(const FilterWater &flt) { return flt.volume; }

int main(void) {
  // здесь продолжайте функцию main
  FilterWater filter{type_filter::flt_calcium, 153564646, 108};
  //  С помощью дружественных функций прочитайте эти значения из объекта filter
  //  и по порядку (type date volume) через пробел выведите на экран.
  std::cout << get_type_filter(filter) << " " << get_date_filter(filter) << " "
            << get_volume_filter(filter) << std::endl;

  // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно
  // идти непосредственно перед return 0 или перед освобождением памяти)

  return 0;
}
