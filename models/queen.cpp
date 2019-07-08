#include "queen.h"


Queen::Queen(bool white) : Piece(queenSymbol, queenValue, white){}

Queen::~Queen(){}

bool Queen::move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination){
    

    b->matrix[xOrigin][yOrigin] = emptyValue;
    b->matrix[xDestination][yDestination] = this->isWhite() ? this->getValue() : -1*this->getValue();
    return true;
}