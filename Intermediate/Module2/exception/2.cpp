#include <iostream>
#include <format>
#include <limits>


int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    // Validate the input
    if (std::cin.fail()) {
        std::cerr << "Input error! Please enter a valid number." << std::endl;
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the invalid input
    } else {
        std::string message = std::format("Formatted value: {:d}", number);
    }
    return 0;
}
