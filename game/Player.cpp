//
// Created by nch on 2/28/2019.
//

#include "Player.h"
#include "supplements.h"
#include <string>
#include <cstring>
#include <iostream>


Player::Player(char *name, int c) {
    upperName = new char[strlen(name) + 1];
    upperName = toUpperName(name);
    color = c;
    scores = 0;
}

Player::~Player() {
    delete[] upperName;
    upperName = nullptr;
}

char *Player::toUpperName(char *name) {
    unsigned begin, end = 0;
    char *copyName = new char[strlen(name) + 1];
    copyName[0] = 'a';
    copyName[1] = '\0';
    unsigned i = 0;

    while (true) {
        if (isalpha(name[i])) {
            name[i] = static_cast<char>(toupper(name[i]));
            begin = i;
            end = begin;
            while (true) {
                if (isspace(name[end]) || name[end] == '\0') {
                    strncat(copyName, name + begin, end - begin + 1);
                    i = end;
                    break;
                }
                ++end;
            }

        }
        if (name[i] == '\0') break;
        else ++i;

    }
    return copyName + 1;
}

void Player::play(Matrix matrix) {
    int column;
    int tempScores = 0;

    for (int row = 1; row <= 5; ++row) {
        std::cout << "\tRow: " << row << " " << "Col: ";
        column = validateInput(1, 3);
        if (color == matrix.getSquare(row, column)) {
            std::cout << "\nRight step!\n";
            tempScores++;
        } else {
            std::cout << "\nWrong step!\n" << std::endl;
            break;
        }
    }

    scores = tempScores;

}

