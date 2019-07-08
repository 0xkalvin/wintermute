#include "piece.h"
#ifndef BISHOP_H
#define BISHOP_H


class Bishop : public Piece{
    public:
        Bishop();
        ~Bishop();
        void move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination);

};

#endif