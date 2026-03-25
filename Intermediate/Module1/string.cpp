#include <iostream>
#include <string>
#include <map>

int main() {
    char str[100] = "Hello, World!";
    std::cout << "String: " << str << std::endl;

    // Modify the string
    str[7] = 'C';
    str[8] = '+';
    str[9] = '+';
    std::cout << "Modified String: " << str << std::endl;

    // Calculate string length
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    std::cout << "String Length: " << length << std::endl;

    // c++ style string
    std::string cppStr = "Hello, C++!";
    cppStr += " Welcome to string handling.";
    auto position = cppStr.find("C++");
    std::cout << "Position of 'C++': " << position << std::endl;
    std::cout << "C++ String: " << cppStr << " Length: " << cppStr.length() << std::endl;

    auto i = cppStr.begin();
    std::cout << "First character: " << *i << std::endl;

    // iterator example
    for (auto it = cppStr.begin(); it != cppStr.end(); ++it) {
        std::cout << *it << " ";
    }

    std::map<std::string, int> wages = {
        {"Alice", 50000},
        {"Bob", 60000},
        {"Charlie", 55000}
    };

    wages["Bob"] += 65000; // Adding a new entry


    std::cout << "\nWages:" << std::endl;

    for (const auto& pair : wages) {
        std::cout << pair.first << ": $" << pair.second << std::endl;
    }
    

    return 0;
}
