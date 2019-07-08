#include "queen.h"


Queen::Queen() : Piece('Q', 10){}

Queen::~Queen(){}

void Queen::move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination){
    

    b->matrix[xOrigin][yOrigin] = 0;
    b->matrix[xDestination][yDestination] = this->getValue();
}