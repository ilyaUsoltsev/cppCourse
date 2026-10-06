class Volume {
  double vol{0.0};

public:
  int operator++() {
    vol += 0.1;
    return 0;
  }
  double operator++(int) {
    double r = vol;
    vol += 0.1;
    return r;
  }

  double operator--() {
    vol -= 0.1;
    return vol;
  }

  double operator--(int) {
    double r = vol;
    vol -= 0.1;
    return r;
  }
};

int main() {
  Volume v;
  ++v;
  double a = ++v;
  double b = v++;

  return 0;
}
