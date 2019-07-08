#include "queen.h"


Queen::Queen() : Piece(queenSymbol, queenValue){}

Queen::~Queen(){}

void Queen::move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination){
    

    b->matrix[xOrigin][yOrigin] = emptyValue;
    b->matrix[xDestination][yDestination] = this->getValue();
}