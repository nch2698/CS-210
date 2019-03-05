//
// Created by nch on 2/25/2019.
//

#include "Matrix.h"
#include "supplements.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

Matrix::Matrix() {
    srand((unsigned) time(nullptr));

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            // check for color duplication in the row to randomize new color.
            do {
                square[i][j] = rand() % 3;
            } while (isDuplicated(j, square[i]));
        }

    }
}

void Matrix::changeSquareColor(int row, int column, int colorValue) {
    --row;
    --column;
    if (square[row][column] != colorValue) {
        // swap the color of another square with the desired one
        for (int i = 0; i < 3; ++i) {
            if (square[row][i] == colorValue) {
                square[row][i] = square[row][column];
                square[row][column] = colorValue;
            }
        }
    } else cout << "The square is already " << toColorLabel(colorValue) << endl;
}

void Matrix::printCoordinates() {
    cout << left << setw(12) << "Row \\ Col";
    for (int k = 0; k < 3; ++k) {
        cout << setw(6) << k + 1;
    }
    cout << endl << "          |-----|-----|-----|" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << setw(10) << i + 1 << "|";
        for (int j = 0; j < 3; ++j) {
            cout << setw(2) << i + 1 << setw(3) << j + 1 << "|";
        }
        cout << endl << "          |-----|-----|-----|" << endl;
    }
}


void Matrix::printColorLabels() {
    cout << left << setw(12) << "Row \\ Col";
    for (int k = 0; k < 3; ++k) {
        cout << setw(6) << k + 1;
    }
    cout << endl << "          |-----|-----|-----|" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << setw(10) << i + 1 << "|";
        for (int j = 0; j < 3; ++j) {
            cout << setw(5) << toColorLabel(square[i][j]) << "|";
        }
        cout << endl << "          |-----|-----|-----|" << endl;
    }
}

int Matrix::getSquare(int row, int column) const {
    --row;
    --column;
    return square[row][column];
}
