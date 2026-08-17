#include <iostream>

// здесь объявляйте класс

class Wallet {
private:
    int volume{ 0 };
    bool check_volume(int x);
public:
    Wallet() : volume(0) {
    };
    Wallet(int v) : volume(v) {
    };
    void add(int vol);
    int get_volume();
};

bool Wallet::check_volume(int x) {
    return (x >= 0);
}

void Wallet::add(int vol) {
    if (check_volume(vol)) {
        volume += vol;
    }
}

int Wallet::get_volume() {
    return volume;
}

int main(void)
{
    // здесь продолжайте функцию main
    Wallet wallet = Wallet(544653);
    int vl = wallet.get_volume();


    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}
