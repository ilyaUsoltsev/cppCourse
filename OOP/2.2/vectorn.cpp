#include <iostream>

class VectorN {
private:
    short* coords{ nullptr };
    int dims{ 0 };
public:
    VectorN(short* data, int size) : dims(size) {
        coords = new short[size];

        for (int i = 0; i < size; ++i) {
            coords[i] = data[i];
        }
    }
    VectorN(int size) : dims(size) {
        coords = new short[size];
        for (int i = 0; i < size; ++i) {
            coords[i] = 0;
        }
    }
    VectorN(int x, int y) {
        coords = new short[2];
        this->dims = 2;
        coords[0] = x;
        coords[1] = y;
    }

    const short* get_coords() {
        return coords;
    }
    int get_dims() {
        return dims;
    }
    ~VectorN() {
        if (coords == nullptr) {
            return;
        }

        std::cout << "delete coords: ";

        for (int i = 0; i < dims; ++i) {
            std::cout << coords[i];
            if (i < dims - 1) {
                std::cout << ' ';
            }
        }

        std::cout << '\n';

        delete[] coords;
    }
};

int main() {
    short data[] = { 4, 2, 10, 0, -5 };
    VectorN v1 = 5; // формирование вектора с пятью нулевыми координатами: 0 0 0 0 0
    VectorN v2(1, 2); // формирование вектора с двумя координатами: 1 2
    VectorN v3(data, std::size(data)); // формирование вектора с переданными координатами data
    return 0;
}

