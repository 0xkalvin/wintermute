#include "king.h"


King::King(bool white) : Piece(kingSymbol, kingValue, white){}

King::~King(){}

void King::move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination){
    int xDiff = abs(xOrigin - xDestination);
    int yDiff = abs(yOrigin - yDestination);

    if((abs(xDestination - xOrigin) > 1 || abs(yDestination - yOrigin) > 1) || 
    (xDiff != yDiff && xOrigin != xDestination && yOrigin != yDestination)) 
        throw "King cannot move to that square";

    b->matrix[xOrigin][yOrigin] = emptyValue;
    b->matrix[xDestination][yDestination] = this->isWhite() ? this->getValue() : -1*this->getValue();
}