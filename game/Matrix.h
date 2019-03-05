//
// Created by nch on 2/25/2019.
//

#ifndef GAME_MATRIX_H
#define GAME_MATRIX_H

#include <iostream>

class Matrix {
private:
    int square[5][3];

public:
    Matrix();

    void changeSquareColor(int row, int column, int colorValue);

    void printCoordinates();

    void printColorLabels();

    int getSquare(int row, int column) const;
};


#endif //GAME_MATRIX_H
