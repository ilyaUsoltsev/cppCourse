#include <cstddef>
#include <string>

struct BankAccount {
  std::string fio; // ФИО счета
  long volume{0};  // объем средств на счете

  BankAccount() = default;
  BankAccount(const std::string &fio, long vol) : fio(fio), volume(vol) {}

  long operator+=(long val) {
    volume += val;
    return volume;
  }
  long operator-=(long val) {
    volume -= val;
    return volume;
  }
  long operator*=(double val) {
    volume = static_cast<long>(volume * val);
    return volume;
  }
  long operator/=(long val) {
    volume /= val;
    return volume;
  }
  long operator%=(long val) {
    volume %= val;
    return volume;
  }
};

class Bank {
  enum { max_accounts = 100 }; // максимальное количество счетов
  BankAccount *acs{nullptr};   // массив из счетов
  size_t count{0};             // текущее количество счетов
public:
  Bank() { acs = new BankAccount[max_accounts]; }
  Bank(BankAccount *lst, size_t size) {
    count = (size > max_accounts) ? max_accounts : size;

    acs = new BankAccount[max_accounts];
    for (int i = 0; i < count; ++i)
      acs[i] = lst[i];
  }
  Bank(const Bank &other) : count(other.count) {
    acs = new BankAccount[max_accounts];
    for (int i = 0; i < count; ++i)
      acs[i] = other.acs[i];
  }

  Bank &operator=(const Bank &other) {
    if (this == &other)
      return *this;
    count = other.count;
    for (int i = 0; i < count; ++i)
      acs[i] = other.acs[i];
    return *this;
  }

  ~Bank() { delete[] acs; }

  Bank &operator+=(BankAccount &bankAccount) {

    // check if not present first
    for (int i = 0; i < count; ++i) {
      if (acs[i].fio == bankAccount.fio) {
        return *this; // already present, do not add
      }
    }

    if (count < max_accounts) {
      acs[count++] = bankAccount;
    }
    return *this;
  }

  Bank &operator+=(BankAccount &&bankAccount) {
    // check if not present first
    for (int i = 0; i < count; ++i) {
      if (acs[i].fio == bankAccount.fio) {
        return *this; // already present, do not add
      }
    }

    if (count < max_accounts) {
      acs[count++] = std::move(bankAccount);
    }
    return *this;
  }

  Bank operator+(BankAccount &bankAccount) {
    Bank result = *this;
    result += bankAccount;
    return result;
  }

  Bank operator+(BankAccount &&bankAccount) {
    Bank result = *this;
    result += std::move(bankAccount);
    return result;
  }

  const BankAccount *get_accounts() { return acs; } // возвращает массив acs
  size_t get_count() { return count; } // возвращает значение поля count
};

int main() {
  Bank my_bank;
  my_bank += BankAccount("А. Дзюба", 43056);
  my_bank += BankAccount("П. Гагарина", 1335395);
  my_bank += BankAccount("О. Бузова", 0);
  my_bank += BankAccount("Тимати", -546);

  //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно
  // идти непосредственно перед return 0 или перед
  // освобождением памяти)

  return 0;
}
