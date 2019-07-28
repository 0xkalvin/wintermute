#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <cstdlib>
#include "../config/settings.h"

using namespace std;

class Player;
class Pawn;
class Knight;
class Rook;
class Bishop;
class Queen;
class King;

/**
    Board class 
    
    - Initializes a 8x8 matrix that saves all squares values
    - Prints the action using different colors depending on the square value

 */
class Board{
    private:
        int **matrix;
        friend class Player;
        friend class Pawn;
        friend class Knight;
        friend class Rook;
        friend class Bishop;
        friend class Queen;
        friend class King;

    public:
        Board();
        ~Board();
        void print();

};

#endif