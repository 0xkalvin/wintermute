#ifndef PIECE_H
#define PIECE_H

#include "board.h" 
#include "../config/settings.h"
#include <cstdlib>

class Piece{
    private:
        char symbol;
        int value;
        bool alive;
        int x_position;
        int y_position;
        bool white;
    
    public:
        Piece(char s, int v, bool white);
        ~Piece();
        char getSymbol();
        int getValue();
        bool isAlive();
        bool isWhite();
};



#endif