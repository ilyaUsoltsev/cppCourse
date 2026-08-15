#include <iostream>
#include <cstdlib>

class Vector3D {
    int x, y, z;

public:
    Vector3D(const char* data) {
        x = 0;
        y = 0;
        z = 0;

        char* end;

        x = static_cast<int>(std::strtod(data, &end));

        while (*end == ' ') {
            ++end;
        }

        y = static_cast<int>(std::strtod(end, &end));

        while (*end == ' ') {
            ++end;
        }

        z = static_cast<int>(std::strtod(end, &end));
    }

    Vector3D(const int* data) {
        x = data[0];
        y = data[1];
        z = data[2];
    }

    void get_coords(int& a, int& b, int& c) {
        a = x;
        b = y;
        c = z;
    }
};
