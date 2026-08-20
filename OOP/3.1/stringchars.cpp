#include <cstring>
#include <iostream>

// здесь объявляйте класс

class StringChars {
private:
  char *buffer{nullptr};
  size_t length{0};

public:
  StringChars(const char *str) {
    size_t len = strlen(str);
    buffer = new char[len + 1];
    strcpy(buffer, str);
    length = len;
  }
  StringChars(const StringChars &other) {
    length = other.length;
    buffer = new char[length + 1];
    strcpy(buffer, other.buffer);
  }
  StringChars operator+(const StringChars &other) const {
    size_t new_length = length + other.length;
    char *new_buffer = new char[new_length + 1];
    strcpy(new_buffer, buffer);
    strcat(new_buffer, other.buffer);
    StringChars result(new_buffer);
    delete[] new_buffer;
    return result;
  }
  ~StringChars() { delete[] buffer; }
  char *to_str() const { return buffer; }
  size_t get_length() const { return length; }
};

int main(void) {
  // здесь продолжайте функцию main
  StringChars *ptr_str1 = new StringChars("Language");
  StringChars *ptr_str2 = new StringChars("C++");
  StringChars res = *ptr_str1 + *ptr_str2;

  //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно
  // идти непосредственно перед return 0 или перед
  // освобождением памяти)

  // здесь освобождайте память (если необходимо)
  delete ptr_str1;
  delete ptr_str2;

  return 0;
}
