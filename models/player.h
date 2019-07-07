#ifndef PLAYER_H
#define PLAYER_H

#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

#include "board.h"

class Player{
    private:
        Pawn *pawn;
        Rook *rook;
        Knight *knight;
        Bishop *bishop;
        Queen *queen;
        King *king;


    public:
        Player(Board *b, char color);
        ~Player();
        void move();

};



#endif