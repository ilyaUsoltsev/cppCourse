#include <iostream>

class Operator {
  int type{0};
  short operation{-1};

private:
  Operator() = default;
  Operator(const Operator &) = delete;

public:
  static Operator *create() { return new Operator(); }

  void set_state(int t, short o) {
    type = t;
    operation = o;
  }

  void get_state(int &t, short &o) {
    t = type;
    o = operation;
  }
};

int main() {
  Operator *op = Operator::create();

  op->set_state(10, 5);

  int type;
  short operation;
  op->get_state(type, operation);

  std::cout << type << ' ' << operation << '\n';

  delete op;

  return 0;
}
