#include <iostream>
#include <iomanip>
#include <string>
int main() {
    std::string name = "John Smith";
    int customerID = 1234;
    double balance = 456.789;   
    // Header
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;
    std::cout << std::setfill(' ') << "CUSTOMER INFORMATION" << std::endl;
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl; 
    // Data display
    std::cout << std::setfill(' ') << std::left;
    std::cout << std::setw(15) << "Name:" << name << std::endl;
    std::cout << std::setw(15) << "Customer ID:" << customerID << std::endl;
    std::cout << std::setw(15) << "Balance:" << std::fixed << std::setprecision(2) << "$" << balance << std::endl;  
    return 0;
}
