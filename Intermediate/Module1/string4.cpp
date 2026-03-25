#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

double averageWordLength(const std::string& input) {
    std::string cleaned;

    // Replace non-alphanumeric characters with spaces
    for (char ch : input) {
        if (std::isalnum(static_cast<unsigned char>(ch))) {
            cleaned += ch;
        } else {
            cleaned += ' ';
        }
    }

    std::istringstream iss(cleaned);
    std::string word;
    int wordCount = 0.0;
    int totalLength = 0.0;

    while (iss >> word) {
        totalLength += word.length();
        wordCount++;
    }

    if (wordCount == 0) {
        return 0.0;
    }

    return static_cast<double>(totalLength) / wordCount;
}

int main() {
    std::string text = "Hello, world! This is a test.";

    std::cout << averageWordLength(text) << std::endl;

    return 0;
}
