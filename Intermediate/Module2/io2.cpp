#include <iostream>
#include <limits>
int main() {
    int age;    
    std::cout << "Enter customer age: ";
    while (!(std::cin >> age) || age < 0 || age > 120) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter an age between 0 and 120: ";
    }   
    std::cout << "Age entered: " << age << std::endl;
    return 0;
}
