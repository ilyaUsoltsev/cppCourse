#include <iostream>
#include <string>

class Point {
    float x, y;

public:
    Point() : x(0), y(0) {
    }

    Point(float a, float b) : x(a), y(b) {
    }

    Point(const char* data) {
        std::string str(data);

        size_t space = str.find(' ');

        x = std::stoi(str.substr(0, space));

        while (space < str.length() && str[space] == ' ') {
            ++space;
        }

        size_t next_space = str.find(' ', space);
        std::cout << "next_space: " << next_space << std::endl;
        y = std::stoi(str.substr(space, next_space - space));
    }

    void print() {
        std::cout << x << " " << y << std::endl;
    }

    float get_x() {
        return x;
    }

    float get_y() {
        return y;
    }
};

int main() {
    Point p1 = "-5.5  -0.78";

    p1.print();

    return 0;
}
