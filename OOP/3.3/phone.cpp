#include <iostream>
#include <string>

struct PhoneBookItem {
  std::string fio;          // ФИО контакта
  std::string phone_number; // номер телефона

  PhoneBookItem() = default;
  PhoneBookItem(std::string fio, std::string phone_number)
      : fio(fio), phone_number(phone_number) {}
};

class PhoneBook {
  enum { max_phone_book = 100 };      // максимальная емкость телефонной книжки
  PhoneBookItem *phone_book{nullptr}; // массив из записей
  size_t count{0};                    // количество записей в телефонной книжке
public:
  const PhoneBookItem *get_phone_book() const { return this->phone_book; }

  size_t get_count() const { return this->count; }

  bool append(const PhoneBookItem &item) {
    if (count == 100) {
      return false;
    } else {
      phone_book[count++] = item;
      return true;
    }
  }

  PhoneBook() { phone_book = new PhoneBookItem[max_phone_book]; }
  PhoneBook(PhoneBookItem *lst, size_t size) {
    count = (size > max_phone_book) ? max_phone_book : size;

    phone_book = new PhoneBookItem[max_phone_book];
    for (int i = 0; i < count; ++i)
      phone_book[i] = lst[i];
  }

  PhoneBook operator+(const PhoneBookItem &item) const {
    PhoneBook result(*this);
    result.append(item);
    return result;
  }

  PhoneBook &operator=(const PhoneBook &other) {
    if (this != &other) {
      PhoneBookItem *new_phone_book = new PhoneBookItem[max_phone_book];

      for (size_t i = 0; i < other.count; ++i)
        new_phone_book[i] = other.phone_book[i];

      delete[] phone_book;
      phone_book = new_phone_book;
      count = other.count;
    }

    return *this; // runs the copy assignment operator
  }

  PhoneBook(const PhoneBook &other)
      : count(other.count), phone_book(new PhoneBookItem[max_phone_book]) {
    for (size_t i = 0; i < count; ++i)
      phone_book[i] = other.phone_book[i];
  }

  ~PhoneBook() { delete[] phone_book; }
};

int main() {
  // здесь продолжайте функцию main
  PhoneBook phone_lst;
  phone_lst.append(PhoneBookItem("А. Дзюба", "+71237694401"));
  phone_lst.append(PhoneBookItem("П. Гагарина", "+79234694105"));
  phone_lst.append(PhoneBookItem("О. Бузова", "+79041563055"));
  phone_lst.append(PhoneBookItem("Тимати", "+79121000000"));

  // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно
  // идти непосредственно перед return 0 или перед освобождением памяти)

  // здесь освобождайте память

  return 0;
}
