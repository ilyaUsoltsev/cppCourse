#include <iostream>
#include <iterator>

class IntOperator {
private:
    int* data{ nullptr };
    int size{ 0 };
public:
    IntOperator() : data(nullptr), size(0) {
    }
    IntOperator(int* dt, int size) : data(dt), size(size) {
    }
    double average() {
        if (size == 0) {
            return 0.0;
        }
        double sum = 0.0;
        for (int i = 0; i < size; ++i) {
            sum += data[i];
        }
        return sum / size;
    }
    int sum() {
        int total = 0;
        for (int i = 0; i < size; ++i) {
            total += data[i];
        }
        return total;
    }
    int max() {
        if (size == 0) {
            return 0;
        }
        int max_value = data[0];
        for (int i = 1; i < size; ++i) {
            if (data[i] > max_value) {
                max_value = data[i];
            }
        }
        return max_value;
    }
    int min() {
        if (size == 0) {
            return 0;
        }
        int min_value = data[0];
        for (int i = 1; i < size; ++i) {
            if (data[i] < min_value) {
                min_value = data[i];
            }
        }
        return min_value;
    }
    ~IntOperator() {
        // zero out all array values
        for (int i = 0; i < size; ++i) {
            data[i] = 0;
        }
    }
};

int main() {
    int dt[] = { 0, -5, 2, 10, 7, 22 };

    IntOperator op_1(dt, std::size(dt));
    IntOperator op2(dt, std::size(dt)); // std::size() возвращает число элементов массива data (C++17)
}
