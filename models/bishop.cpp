#include "bishop.h"


Bishop::Bishop() : Piece('B', 4){}

Bishop::~Bishop(){}

void Bishop::move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination){




    b->matrix[xOrigin][yOrigin] = 0;
    b->matrix[xDestination][yDestination] = this->getValue();
}