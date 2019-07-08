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