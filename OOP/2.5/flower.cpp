#include <iostream>

// здесь объявляйте класс
class Flower {
    char name[100] = { 0 };
    int price{ 0 };
public:
    Flower() = delete;
    Flower(const char* name, int price) : price(price)
    {
        int i = 0;
        for (; i < 100 && name[i] != '\0'; ++i) {
            this->name[i] = name[i];
        }
        this->name[i] = '\0'; // ensure null-termination
    };
    void get_data(char* name, int& price)
    {
        int i = 0;
        for (; i < 100 && this->name[i] != '\0'; ++i) {
            name[i] = this->name[i];
        }
        name[i] = '\0'; // ensure null-termination
        price = this->price;
    };
};

int main(void)
{
    // здесь продолжайте функцию main
    Flower flower("Тюльпан", 120);

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}
