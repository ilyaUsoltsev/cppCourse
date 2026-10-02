#include <iostream>
#include <string>

class Animal {
protected:
  std::string name;
  short old{0};

public:
  const std::string &get_name() const { return name; }
  short get_old() const { return old; }
  Animal() = default;
  Animal(const std::string &name, short old) : name(name), old(old) {}
};

class Cat : public Animal {
private:
  int color{0};
  double weight{0.0};

public:
  int get_color() const { return color; }
  double get_weight() const { return weight; }
  void set_info(const std::string &name, short old, int color, double weight) {
    this->name = name;
    this->old = old;
    this->color = color;
    this->weight = weight;
  }
  Cat(const std::string &name, short old, int color, double weight)
      : Animal(name, old), color(color), weight(weight) {}
};

class Dog : public Animal {
private:
  std::string breed;
  short length{0};

public:
  const std::string &get_breed() const { return breed; }
  short get_length() const { return length; }
  void set_info(const std::string &name, short old, const std::string &breed,
                short length) {
    this->name = name;
    this->old = old;
    this->breed = breed;
    this->length = length;
  }
  Dog(const std::string &name, short old, const std::string &breed,
      short length)
      : Animal(name, old), breed(breed), length(length) {}
};
