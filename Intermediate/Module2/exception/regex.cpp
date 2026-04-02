#include <iostream>
#include <regex>
#include <string>
#include <regex>
#include <stdexcept>

bool safeRegexValidation(const std::string& input, const std::string& pattern) {
    try {
        std::regex regex_pattern(pattern);
        return std::regex_match(input, regex_pattern);
    } catch (const std::regex_error& e) {
        std::cerr << "Regex error: " << e.what() << std::endl;
        return false;
    }
}

int main() {
    std::string email = "user@example.com";

    bool isValid = safeRegexValidation(email, "([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+.[a-zA-Z]{2,})");  

    if (isValid) {
        std::cout << "Valid email address" << std::endl;
    } else {
        std::cout << "Invalid email address" << std::endl;
    }
    return 0;
}
