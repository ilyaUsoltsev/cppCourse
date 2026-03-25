#include <iostream>

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matrixB[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {1, 2, 3}
    };

    int result[3][3];

    for (int i = 0; i < 3; ++i) {   
        for (int j = 0; j < 3; ++j) {
            result[i][j] = matrix[i][j] + matrixB[i][j];
             std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int seating[5][5] = {
        {0, 1, 0, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 0, 1, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 0}
        };

        std::cout << "Theater seating chart initialized!" << std::endl;
        std::cout << "0 = Available, 1 = Occupied" << std::endl;

        // count available seats
        int availableSeats = 0;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (seating[i][j] == 0) {
                    availableSeats++;
                }
            }
        }

        std::cout << "Available seats: " << availableSeats << std::endl;

    return 0;
}   
