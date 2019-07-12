#ifndef PIECE_H
#define PIECE_H

#include "board.h" 
#include "../config/settings.h"
#include <cstdlib>

class Pawn;
class Knight;
class Rook;
class Bishop;
class Queen;
class King;


class Piece{
    private:
        char symbol;
        int value;
        bool white;
        int quantity;
        int alive;
        bool moved;
        friend class Pawn;
        friend class Knight;
        friend class Rook;
        friend class Bishop;
        friend class Queen;
        friend class King;
    
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