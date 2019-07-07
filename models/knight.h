#include "piece.h"
#ifndef KNIGHT_H
#define KNIGHT_H


class Knight : public Piece{
    public:
        Knight();
        ~Knight();
        void move(Board *b, int x, int y);

};

#endif