#include "piece.h"
#ifndef PAWN_H
#define PAWN_H

class Pawn : public Piece{
    public:
        Pawn(bool white);
        ~Pawn();
        void move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination);
        void promotion(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination);

};

#endif