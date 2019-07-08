#include "king.h"


King::King(bool white) : Piece(kingSymbol, kingValue, white){}

King::~King(){}

bool King::move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination){
    



    b->matrix[xOrigin][yOrigin] = emptyValue;
    b->matrix[xDestination][yDestination] = this->isWhite() ? this->getValue() : -1*this->getValue();
    return true; 
}