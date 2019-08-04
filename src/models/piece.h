#ifndef PIECE_H
#define PIECE_H

#include "board.h" 
#include "../config/settings.h"
#include <cstdlib>

template <typename P>
class Pawn;

template <typename P>
class Knight;

template <typename P>
class Rook;

template <typename P>
class Bishop;

template <typename P>
class Queen;

template <typename P>
class King;

/**
    Base class for pieces 
    
    - Stores piece value, symbol, color, state

 */
template <typename P>
class Piece{
    private:
        char symbol;
        int value;
        bool white;
        int quantity;
        int alive;
        bool moved;
        friend class Pawn<P>;
        friend class Knight<P>;
        friend class Rook<P>;
        friend class Bishop<P>;
        friend class Queen<P>;
        friend class King<P>;
    
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