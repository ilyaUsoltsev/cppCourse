#include <iostream>

class Distance {
public:
  int dist{0};

  Distance(int d) : dist(d) {}
  int operator+=(int right) {
    this->dist += right;
    return this->dist;
  }
  int operator-=(int right) {
    this->dist -= right;
    return this->dist;
  }
  int operator*=(int right) {
    this->dist *= right;
    return this->dist;
  }
  int operator/=(int right) {
    if (right != 0)
      this->dist /= right;
    return this->dist;
  }
  operator int() { return this->dist; }
};

int main() {
  Distance d1 = 100;
  d1 += 50;               // dist = 150
  Distance d2 = d1 += 10; // dist в d1 и d2 равны 150+10 = 160
  std::cout << d1.dist << std::endl;
  std::cout << d2.dist << std::endl;

  return 0;
}
