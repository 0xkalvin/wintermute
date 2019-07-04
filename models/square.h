#ifndef SQUARE_H
#define SQUARE_H

#include "piece.h"

class Square{
    private:
        Piece *piece;
        int value;
        bool occupied;

    public:
        Square();
        ~Square();
        bool isOccupied();
        int getValue();
        void placePiece(Piece *p);
};



#endif