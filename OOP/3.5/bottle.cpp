class BottleWater {
  enum { max_volume = 640 }; // максимальный объем воды
  short volume{0};           // объем воды в бутылке
public:
  BottleWater(short volume = 0) : volume(volume) {
    this->volume = clamp_volume();
  }

  short get_volume() const { return volume; }

  int clamp_volume() const {
    if (volume > max_volume)
      return max_volume;
    if (volume < 0)
      return 0;
    return volume;
  }

  int operator+=(int right) {
    this->volume += right;
    return this->volume = clamp_volume();
  }

  int operator+=(const BottleWater &right) {
    this->volume += right.volume;
    return this->volume = clamp_volume();
  }

  int operator-=(const BottleWater &right) {
    this->volume -= right.volume;
    return this->volume = clamp_volume();
  }

  int operator*=(const BottleWater &right) {
    this->volume *= right.volume;
    return this->volume = clamp_volume();
  }

  int operator/=(const BottleWater &right) {
    if (right.volume != 0)
      this->volume /= right.volume;
    return this->volume = clamp_volume();
  }

  int operator-=(int right) {
    this->volume -= right;
    return this->volume = clamp_volume();
  }

  int operator*=(int right) {
    this->volume *= right;
    return this->volume = clamp_volume();
  }

  int operator/=(int right) {
    if (right != 0)
      this->volume /= right;
    return this->volume = clamp_volume();
  }

  BottleWater operator+(const BottleWater &right) const {
    BottleWater result(this->volume + right.volume);
    result.volume = result.clamp_volume();
    return result;
  }

  BottleWater operator-(const BottleWater &right) const {
    BottleWater result(this->volume - right.volume);
    result.volume = result.clamp_volume();
    return result;
  }

  BottleWater operator*(const BottleWater &right) const {
    BottleWater result(this->volume * right.volume);
    result.volume = result.clamp_volume();
    return result;
  }

  BottleWater operator/(const BottleWater &right) const {
    BottleWater result(this->volume);
    if (right.volume != 0)
      result.volume /= right.volume;
    result.volume = result.clamp_volume();
    return result;
  }
};

int main() {
  BottleWater bw1(40), bw2(200);
  BottleWater res = bw1 + bw2;

  //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно
  // идти непосредственно перед return 0 или перед
  // освобождением памяти)

  return 0;
}
