#include <iostream>
#include <string>

// здесь объявляйте класс
class Complex {
private:
    short re{ 0 }, im{ 0 };
public:
    Complex() : re(0), im(0) {
    }

    Complex(short r) : re(r), im(0) {
    }

    Complex(short r, short i) : re(r), im(i) {
    }

    Complex(Complex& c) {
        this->re = c.real() < 0 ? -c.real() : c.real();
        this->im = c.imag() < 0 ? -c.imag() : c.imag();
    }

    short real() {
        return re;
    }
    short imag() {
        return im;
    }
};

int main(void)
{
    // здесь продолжайте функцию main
    Complex digit(-4, 7);
    Complex res = digit;

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}
