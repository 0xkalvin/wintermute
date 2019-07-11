#ifndef GAME_H
#define GAME_H

#include "player.h"

class Game{
    private:
        Board *board;
        Player *white;
        Player *black;
        bool isOver;
        int moves;
        char lastMove[2];

    public:
        Game();
        ~Game();
        void print();
        void input();
        void run();
        void capturedPieces();

};

#endif