#include "piece.h"
#ifndef ROOK_H
#define ROOK_H


class Rook : public Piece{
    public:
        Rook();
        ~Rook();
        void move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination);

};

#endif