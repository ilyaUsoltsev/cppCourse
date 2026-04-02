#include <iostream>
#include <string>
#include <sstream>

int main() {
    int integer = -1;

    std::string integers = "1 2 3 4 5 notInteger 6 7 8 9 10";
    std::istringstream integerStream(integers);

    try {
        integerStream.exceptions(std::ios::failbit | std::ios::badbit);
        while (integerStream >> integer) {
            std::cout << "Read integer: " << integer << std::endl;
        }
        std::cout << "Finished reading integers." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
