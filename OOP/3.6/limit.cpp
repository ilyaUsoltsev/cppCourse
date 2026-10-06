class LimitLength {
  enum { min_length = -10, max_length = 10 }; // границы допустимых значений
  int length{0};                              // текущее значение
public:
  LimitLength(int len = 0) : length(len) {}

  int get_length() const { return length; }

  int operator++() {
    if (length < max_length) {
      ++length;
    }
    return length;
  }

  int operator++(int) {
    int old_length = length;
    if (length < max_length) {
      ++length;
    }
    return old_length;
  }

  int operator--() {
    if (length > min_length) {
      --length;
    }
    return length;
  }

  int operator--(int) {
    int old_length = length;
    if (length > min_length) {
      --length;
    }
    return old_length;
  }

  int operator+=(int value) {
    if (length + value > max_length) {
      length = max_length;
    } else if (length + value < min_length) {
      length = min_length;
    } else {
      length += value;
    }
    return length;
  }

  int operator-=(int value) {
    if (length - value > max_length) {
      length = max_length;
    } else if (length - value < min_length) {
      length = min_length;
    } else {
      length -= value;
    }
    return length;
  }

  int operator*=(int value) {
    if (length * value > max_length) {
      length = max_length;
    } else if (length * value < min_length) {
      length = min_length;
    } else {
      length *= value;
    }
    return length;
  }

  int operator/=(int value) {
    if (value == 0) {
      return length; // деление на ноль не изменяет значение
    }
    if (length / value > max_length) {
      length = max_length;
    } else if (length / value < min_length) {
      length = min_length;
    } else {
      length /= value;
    }
    return length;
  }
};

int main() {
  LimitLength lm1 = -5;
  int a = lm1++;
  int b = ++lm1;
  int c = lm1--;
  int d = --lm1;
  int res_1 = lm1 += 5;
  int res_2 = lm1 -= 15;
  int res_3 = lm1 *= 2;
  int res_4 = lm1 /= 3;
}
