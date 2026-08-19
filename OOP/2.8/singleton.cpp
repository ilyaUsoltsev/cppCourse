#include <iostream>

class Singleton {
  int data{0};
  static Singleton *instance_ptr;

  Singleton() {}

public:
  Singleton(const Singleton &) = delete;
  ~Singleton() { instance_ptr = nullptr; }

  static Singleton *get_instance() {
    if (instance_ptr == nullptr) {
      instance_ptr = new Singleton();
    }
    return instance_ptr;
  }

  void set_data(int d) { data = d; }
  int get_data() { return data; }
};

Singleton *Singleton::instance_ptr = nullptr;

int main() {
  Singleton *ptr = Singleton::get_instance();
  ptr->set_data(1);
  Singleton *ptr2 = Singleton::get_instance();

  std::cout << ptr << " " << ptr2 << std::endl;
  std::cout << ptr2->get_data() << std::endl;

  delete ptr;
  return 0;
}
