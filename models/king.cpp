#include "king.h"


King::King() : Piece(kingSymbol, kingValue){}

King::~King(){}

void King::move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination){
    



    b->matrix[xOrigin][yOrigin] = emptyValue;
    b->matrix[xDestination][yDestination] = this->getValue();
}