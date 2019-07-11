#ifndef PIECE_H
#define PIECE_H

#include "board.h" 
#include "../config/settings.h"
#include <cstdlib>

class Piece{
    private:
        char symbol;
        int value;
        bool white;
        int quantity;
        int alive;
    
    public:
        Piece(char s, int v, bool white, int q);
        ~Piece();
        char getSymbol();
        int getValue();
        bool isWhite();
        int getQuantity();
        void captured();
        int getAlive();
};



#endif