#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

int countWords(const std::string& input) {
    std::string cleaned;

    // Step 1: Replace punctuation with spaces
    for (char ch : input) {
        if (std::isalnum(ch)) {
            cleaned += ch;
        } else {
            cleaned += ' ';
        }
    }

    // Step 2: Use istringstream to extract words
    std::istringstream iss(cleaned);
    std::string word;
    int count = 0;

    while (iss >> word) {
        count++;
    }

    return count;
}

int main() {
    std::string text = "Hello, world! This is a test.";

    std::cout << countWords(text) << std::endl; // Output: 6

    return 0;
}
