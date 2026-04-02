#include <regex>
#include <iostream>
bool isValidSimpleJSON(const std::string& json) {
    // Pattern for simple JSON object: {"key": "value", "key2": "value2"}
    std::regex json_pattern(R"(\s*\{\s*("[\w\s]+"\s*:\s*"[^"]*"\s*,?\s*)*\}\s*)");
    return std::regex_match(json, json_pattern);
}
int main() {
    std::string test_json = R"({"name": "John", "age": "25"})";

    if (isValidSimpleJSON(test_json)) {
        std::cout << "Valid JSON structure" << std::endl;
    } else {
        std::cout << "Invalid JSON format" << std::endl;
    }   
    return 0;
}
