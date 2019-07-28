#ifndef GAME_H
#define GAME_H

#include "player.h"

/**
    Game class 
    
    - Initializes the players & the board
    - Controls and validates player input
    - Prints the action

 */
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
        void showCapturedPieces();

};

#endif