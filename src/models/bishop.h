#include "piece.h"
#ifndef BISHOP_H
#define BISHOP_H


template <typename P>
class Bishop : public Piece<P>{
    public:
        Bishop(bool white);
        ~Bishop();
        void move(Board<P> *b, int xOrigin, int yOrigin, int xDestination, int yDestination);

};

#endif