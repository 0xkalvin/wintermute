#include "piece.h"
#ifndef ROOK_H
#define ROOK_H


template <typename P>
class Rook : public Piece<P>{
    public:
        Rook(bool white);
        ~Rook();
        void move(Board<P> *b, int xOrigin, int yOrigin, int xDestination, int yDestination);

};

#endif