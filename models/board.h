#ifndef BOARD_H
#define BOARD_H

#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

class Player;


class Board{
    private:
        int **matrix;
        friend class Player;

        Piece **board;


    public:
        Board();
        ~Board();
        void print();

};

#endif