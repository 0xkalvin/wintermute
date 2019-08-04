#include "piece.h"
#ifndef KNIGHT_H
#define KNIGHT_H


template <typename P>
class Knight : public Piece<P>{
    public:
        Knight(bool white);
        ~Knight();
        void move(Board<P> *b, int xOrigin, int yOrigin, int xDestination, int yDestination);

};

#endif