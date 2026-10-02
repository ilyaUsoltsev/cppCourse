
#include <iostream>

struct S {
  int x = 19;

  int *foo() & {
    std::cout << "lvalue: " << x << std::endl;
    return &x;
  }
  int *foo() && {
    std::cout << "rvalue: " << x << std::endl;
    return &x;
  }
};

extern S bar();

int main() {
  S x;

  int *a = x.foo();
  *S{}.foo() = 42;
}
