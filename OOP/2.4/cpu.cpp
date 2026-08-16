#include <iostream>
#include <string>

struct CPU {
    std::string model; // модель CPU
    double fr; // тактовая частота (в ГГц)
public:
    CPU(const std::string& model, double fr) : model(model), fr(fr)
    {
    }
    CPU() {
    }
};

struct Memory {
    std::string name; // наименование
    unsigned long long volume; // размер памяти (в байтах)
public:
    Memory(const std::string& name, unsigned long long volume) : name(name), volume(volume)
    {
    }
    Memory() {
    }
};

class MotherBoard {
    CPU cpu;
    Memory mems[2];
public:
    MotherBoard(const CPU& cpu, const Memory& mem_1, const Memory& mem_2)
        : cpu(cpu), mems{ mem_1, mem_2 }
    {
    }
    CPU& get_cpu() {
        return cpu;
    }
    Memory* get_mems() {
        return mems;
    }
};

int main(void)
{
    // здесь продолжайте функцию main

    CPU cpu{ "CORE i5", 1.7 };
    Memory Memory1{ "Samsung", 4000000000 };
    Memory Memory2{ "Kingston", 8000000000 };

    MotherBoard* ptr_mb = new MotherBoard(cpu, Memory1, Memory2);

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память

    delete ptr_mb;

    return 0;
}
