#include "piece.h"
#ifndef PAWN_H
#define PAWN_H

template <typename P>
class Pawn : public Piece<P>{
    public:
        Pawn(bool white);
        ~Pawn();
        void move(Board<P> *b, int xOrigin, int yOrigin, int xDestination, int yDestination);
        void promotion(Board<P> *b, int xOrigin, int yOrigin, int xDestination, int yDestination);

};

#endif