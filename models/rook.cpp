#include "rook.h"


Rook::Rook(bool white) : Piece(rookSymbol, rookValue, white, rookQuantity){}

Rook::~Rook(){}


/**
    Rook movement
    
    - Checks if it's moving in the same line or column 
    - Cannot change line and column at the same time

 */
void Rook::move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination){
    if(xOrigin != xDestination && yOrigin != yDestination){
        throw "Rook cannot move to that square";
    } 
    
    b->matrix[xOrigin][yOrigin] = emptyValue;
    b->matrix[xDestination][yDestination] = this->isWhite() ? this->getValue() : -1*this->getValue();
    
}