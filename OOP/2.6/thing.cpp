#include <iostream>

// здесь объявляйте класс

class Thing {
private:
    long id{ 0 };
    int price{ 0 };
    double weight{ 0.0 };
    bool check_price(int x) {
        return x >= 0;
    }
    bool check_weight(double x) {
        return x >= 0.0;
    }

public:
    Thing(long id, int price, double weight)
    {
        this->id = id;
        if (check_price(price)) {
            this->price = price;
        }
        if (check_weight(weight)) {
            this->weight = weight;
        }
    }
    Thing() : id(0), price(0), weight(0.0) {
    }
    void get_info(long& id, int& price, double& weight) {
        id = this->id;
        price = this->price;
        weight = this->weight;
    }
};

int main(void)
{
    // здесь продолжайте функцию main
    Thing th = Thing(5, 53403, 87.4);

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}
