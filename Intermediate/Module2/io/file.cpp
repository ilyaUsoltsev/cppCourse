// open and read a file
#include <iostream>
#include <fstream>
#include <string>   

int main() {
    std::ifstream inputFile("data.txt"); // Open the file for reading

    if (!inputFile) { // Check if the file was opened successfully
        std::cerr << "Error opening file!" << std::endl;
        return 1; // Exit with an error code
    }

    std::string line;
    int lineNumber = 1;
    while (std::getline(inputFile, line)) { // Read the file line by line

        // add EVEN and ODD line numbers
        if (lineNumber % 2 == 0) {
            std::cout << "EVEN LINE " << lineNumber << ": ";
        } else {
            std::cout << "ODD LINE " << lineNumber << ": ";
        }

        std::cout << line << std::endl; // Output each line to the console
        // mark last line read with a special character
        if (inputFile.eof()) {
            std::cout << "END OF FILE REACHED" << std::endl; // Indicate that the end of the file has been reached
        }
        lineNumber++;
    }

    inputFile.close(); // Close the file
    return 0; // Exit with success
}
