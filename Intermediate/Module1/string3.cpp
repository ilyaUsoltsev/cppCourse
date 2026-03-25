#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

bool isPalindrome(const std::string& input) {
    std::string cleaned;

    // Step 1: filter + normalize
    std::copy_if(input.begin(), input.end(), std::back_inserter(cleaned),
        [](unsigned char ch) {
            return std::isalpha(ch);
        });

    // Convert to lowercase
    std::transform(cleaned.begin(), cleaned.end(), cleaned.begin(),
        [](unsigned char ch) {
            return std::tolower(ch);
        });

    // Step 2: check palindrome
    std::string reversed = cleaned;
    std::reverse(reversed.begin(), reversed.end());

    return cleaned == reversed;
}

int main() {
    std::string text = "A man, a plan, a canal: Panama";

    if (isPalindrome(text)) {
        std::cout << "Palindrome\n";
    } else {
        std::cout << "Not a palindrome\n";
    }

    return 0;
}
