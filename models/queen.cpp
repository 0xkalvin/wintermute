#include "queen.h"


Queen::Queen(bool white) : Piece(queenSymbol, queenValue, white, queenQuantity){}

Queen::~Queen(){}

void Queen::move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination){
    int xDiff = abs(xOrigin - xDestination);
    int yDiff = abs(yOrigin - yDestination);

    if(xDiff != yDiff && xOrigin != xDestination && yOrigin != yDestination) throw "Queen cannot move to that square";
    
    b->matrix[xOrigin][yOrigin] = emptyValue;
    b->matrix[xDestination][yDestination] = this->isWhite() ? this->getValue() : -1*this->getValue();
}