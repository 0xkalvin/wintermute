#include "piece.h"
#ifndef KNIGHT_H
#define KNIGHT_H


class Knight : public Piece{
    public:
        Knight();
        ~Knight();
        void move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination);

};

#endif