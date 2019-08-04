#include "piece.h"
#ifndef KING_H
#define KING_H

template <typename P>
class King : public Piece<P>{
    public:
        King(bool white);
        ~King();
        void move(Board<P> *b, int xOrigin, int yOrigin, int xDestination, int yDestination);
        void castle(Board<P> *b, int xOrigin, int yOrigin, int xDestination, int yDestination);

};

#endif