#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <cstdlib>
#include "../config/settings.h"
#include "square.cpp"

using namespace std;

template <typename P>
class Player;

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
    Board class 
    
    - Initializes a 8x8 matrix that saves all squares values
    - Prints the action using different colors depending on the square value

 */
template <typename P>
class Board{
    private:
        Square<P> **matrix;
        friend class Player<P>;
        friend class Pawn<P>;
        friend class Knight<P>;
        friend class Rook<P>;
        friend class Bishop<P>;
        friend class Queen<P>;
        friend class King<P>;
    public:
        Board();
        ~Board();
        void print();

};

#endif