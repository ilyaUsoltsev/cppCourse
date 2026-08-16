#include <iostream>

// здесь объявляйте класс

class Graph
{
private:
    double* data{ nullptr };
    int length{ 0 };

public:
    Graph() = default;

    Graph(const double* ar, int size)
    {
        set_data(ar, size);
    }

    ~Graph()
    {
        delete[] data;
    }

    void set_data(const double* ar, int size)
    {
        delete[] data;

        data = new double[size];

        for (int i = 0; i < size; ++i)
            data[i] = ar[i];

        length = size;
    }

    double* get_data()
    {
        return data;
    }

    int get_length()
    {
        return length;
    }
};


int main(void)
{
    // здесь продолжайте функцию main

    Graph gr;

    double coords[] = { 5, 0.4, 2.7, -3.2 };
    gr.set_data(coords, sizeof(coords) / sizeof(*coords));

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}
