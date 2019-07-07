#include "piece.h"
#ifndef QUEEN_H
#define QUEEN_H


class Queen : public Piece{
    public:
        Queen();
        ~Queen();
        void move(Board *b, int x, int y);

};

#endif