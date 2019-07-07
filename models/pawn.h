#include "piece.h"
#ifndef PAWN_H
#define PAWN_H



class Pawn : public Piece{
    public:
        Pawn();
        ~Pawn();
        void move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination);

};

#endif