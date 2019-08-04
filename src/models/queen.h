#include "piece.h"
#ifndef QUEEN_H
#define QUEEN_H


template <typename P>
class Queen : public Piece<P>{
    public:
        Queen(bool white);
        ~Queen();
        void move(Board<P> *b, int xOrigin, int yOrigin, int xDestination, int yDestination);

};

#endif