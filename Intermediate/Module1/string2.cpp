#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>

std::unordered_map<char, int> countCharacters(const std::string& text) {
    std::unordered_map<char, int> freq;

    for (char ch : text) {
        // Step 1: keep only alphabetic characters
        if (std::isalpha(ch)) {
            // Step 2: normalize to lowercase
            char lower = std::tolower(ch);

            // Step 3: count
            freq[lower]++;
        }
    }

    return freq;
}

int main() {
    std::string text = "Hello, World!";

    auto result = countCharacters(text);

    for (const auto& [ch, count] : result) {
        std::cout << ch << ": " << count << std::endl;
    }

    return 0;
}
