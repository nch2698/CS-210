//
// Created by nch on 2/28/2019.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "Matrix.h"

class Player {
private:
    char *upperName;
    int scores;
    int color;

    char *toUpperName(char *name);

public:
    Player(char* name, int color);

    ~Player();

    const char *getName() const { return upperName; }

    int getScores() const { return scores; }

    int getColor() const { return color; }

    void play(Matrix matrix);

};


#endif //GAME_PLAYER_H
