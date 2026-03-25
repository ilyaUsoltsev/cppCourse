#include <iostream>
#include <string>   

int main() {
        int position = 0;
        std::string text = "Hello, world! This is a test.";
        position = text.find("world", position);
        std::cout << position << std::endl; // Output: 7
        text.replace(position, 5, "C++");
        std::cout << text << std::endl; // Output: Hello, C++!
    
}
