#ifndef GAME_H
#define GAME_H

#include "board.h"


class Game{
    private:
        Board *board;

    public:
        Game();
        ~Game();
        void print();

};

#endif