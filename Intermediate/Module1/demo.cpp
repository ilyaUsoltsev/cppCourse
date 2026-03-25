#include <iostream>
#include <array>
#include <algorithm>

template <size_t N>
void bubbleSort(std::array<int, N>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        bool swapped = false;
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main() {
    
    int numbers[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; ++i) {
        std::cout << numbers[i] << " ";
    }

    std::array<int, 5> modernNumbers = {1, 2, 3, 43, 5};
    

    std::cout << modernNumbers.at(1) << std::endl; 
    std::cout << modernNumbers.size() << std::endl;

    // traverse using indexing
    for (size_t i = 0; i < modernNumbers.size(); ++i) {
        std::cout << modernNumbers[i] << " ";
    }
    std::cout << std::endl;

    std::sort(modernNumbers.begin(), modernNumbers.end(), std::less<int>());

    std::array<int, 7> moreNumbers = {23, 20, 30, 40, 5};
    moreNumbers[5] = 15;
    bubbleSort(moreNumbers);

    int find = 333;
    auto it = std::find(modernNumbers.begin(), modernNumbers.end(), find);
    if (it != modernNumbers.end()) {
        std::cout << "Element found: " << *it << std::endl;
    } else {
        std::cout << "Element not found." << std::endl;
    }
    for (const auto& element : moreNumbers) {
                std::cout << element << " ";
            }

    return 0;
}
