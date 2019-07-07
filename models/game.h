#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"

class Game{
    private:
        Board *board;
        Player *white;
        Player *black;
        bool isOver;
        int moves;

    public:
        Game();
        ~Game();
        void print();
        void input();
        void run();

};

#endif