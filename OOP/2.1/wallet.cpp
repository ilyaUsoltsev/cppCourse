#include <iostream>

// здесь объявляйте класс

class Wallet {
public:
private:
    long volume{ 0 };
public:
    Wallet(long volume = 0) : volume(volume) {
    }
    void set_volume(long volume) {
        this->volume = volume;
    }
    long get_volume() {
        return this->volume;
    }
};

int main(void)
{
    // здесь продолжайте функцию main
    Wallet w1, w2(1000);
    Wallet* ptr_w1 = new Wallet();
    Wallet* ptr_w2 = new Wallet(5000);

    delete ptr_w1;
    delete ptr_w2;
    return 0;
}
