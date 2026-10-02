#include <string>

class BankAccount {
public:
  std::string fio;
  long volume_rub{0};

  const std::string &get_fio() const { return this->fio; }

  long get_volume_rub() const { return this->volume_rub; }

  BankAccount(const std::string &fio_, long volume_rub_ = 0)
      : fio(fio_), volume_rub(volume_rub_) {}

  BankAccount &operator=(long volume_rub_) {
    volume_rub = volume_rub_;
    return *this;
  }

  BankAccount &operator=(const BankAccount &) = delete;

  long operator+=(long volume_rub_) {
    volume_rub += volume_rub_;
    return volume_rub;
  }

  long operator-=(long volume_rub_) {
    volume_rub -= volume_rub_;
    return volume_rub;
  }

  long operator+=(BankAccount const &other) {
    this->volume_rub += other.volume_rub;
    return this->volume_rub;
  }
  long operator-=(BankAccount const &other) {
    this->volume_rub -= other.volume_rub;
    return this->volume_rub;
  }
};

int main() {
  BankAccount account("John Doe", 1000);
  BankAccount another_account("Jane Doe", 500);
  account = 1000;
}
