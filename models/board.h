#ifndef BOARD_H
#define BOARD_H

#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"



class Board{
    private:
        int **matrix;
        Pawn *pawn;
        Rook *rook;
        Knight *knight;
        Bishop *bishop;
        Queen *queen;
        King *king;

    public:
        Board();
        ~Board();
        void init();
        void print();

};

#endif