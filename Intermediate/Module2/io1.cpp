#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


int main() {
    std::cout << std::left << std::setw(15) << "Name" << std::setw(10) << "Score" << std::endl;
    std::cout << std::left << std::setw(20) << "Alice" << std::setw(10) << 88 << std::endl;

    std::cout << std::left << std::setw(12) << "Product"
        << std::setw(8) << "Price"
        << std::setw(16) << "Quantity Available" << std::endl;
std::cout << std::left << std::setw(12) << "Apples"
         << std::setw(8) << "$1.20"
        << std::setw(16) << "150" << std::endl;

    int number;
    while (!(std::cin >> number)) {
        std::cin.clear(); // Reset the state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear invalid input
        std::cout << "Invalid input, please enter a number: ";
    }
    std::cout << "You entered: " << number << std::endl;

    return 0;
}
