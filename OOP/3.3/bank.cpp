#include <iostream>
#include <string>

class BankAccount {
private:
  std::string fio;
  long volume_rub{0};

public:
  BankAccount(std::string input, long money = 0)
      : fio(input), volume_rub(money) {}
  BankAccount &operator=(long value) {
    this->volume_rub = value;
    return *this;
  }
  const std::string &get_fio() { return this->fio; }
  long get_volume_rub() { return this->volume_rub; }
};

int main() {
  BankAccount a1("Balakirev");
  a1 = 10000;
  return 0;
}
