#include <iostream>
#include <string>

// здесь объявляйте класс

class Thing {
private:
    std::string name;
    double weight{ 0 };
    int price{ 0 };
public:
    Thing() : price(0), weight(0) {
        std::cout << "default constructor";
    }

    Thing(std::string bookName) : name(bookName) {
        std::cout << "constructor 1" << "\n";
    }

    Thing(std::string bookName, double w, int p) : Thing(bookName) {
        this->weight = w;
        this->price = p;
        std::cout << "constructor 3";
    }

    std::string get_name() {
        return name;
    }
    double get_weight() {
        return weight;
    }
    int get_price() {
        return price;
    }
};

int main(void)
{
    // здесь продолжайте функцию main
    Thing* ptr_th = new Thing("HP Omen", 2.3, 120000);

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память
    delete ptr_th;

    return 0;
}
