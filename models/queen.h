#include "piece.h"
#ifndef QUEEN_H
#define QUEEN_H


class Queen : public Piece{
    public:
        Queen(bool white);
        ~Queen();
        void move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination);

};

#endif