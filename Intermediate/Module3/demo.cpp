#include <iostream>

struct MyStruct {
    int x;
    int y;
};

void increaseValue(int& value) {
    value++;    
}

MyStruct createStruct(int a, int b) {
    MyStruct s;
    s.x = a;
    s.y = b;
    return s;
}

int main() {
    int myValue = 5;
    std::cout << "Original value: " << myValue << std::endl;
    increaseValue(myValue);
    std::cout << "Increased value: " << myValue << std::endl;

    return 0;
}
