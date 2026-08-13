#include <iostream>
#include <string>

class Goods {
    std::string name;  // название
    double weight;  // вес
    int price;   // цена
public:
    void set_data(const std::string &name, double weight, int price)
    {
        this->name = name;
        this->weight = weight;
        this->price = price;        
    }

    const std::string& get_name() const {
        return name;
    }
    double get_weight() const {
        return weight;
    }
    int get_price() const {
        return price;
    }
};

int main()
{
//    В функции main создайте два объекта класса Goods в виде обычных переменных с именами book и toy. В поля этих объектов занесите следующие данные:

// book: name="Основы ООП"; weight=234.5; price=2000
// toy: name="Oculus Quest 3"; weight=204.6; price=80000

    Goods book, toy;
    book.set_data("Основы ООП", 234.5, 2000);
    toy.set_data("Oculus Quest 3", 204.6, 80000);

    return 0;
}
