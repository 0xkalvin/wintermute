#include "rook.h"

template <typename P>
Rook<P>::Rook(bool white) : Piece<P>(rookSymbol, rookValue, white, rookQuantity){}

template <typename P>
Rook<P>::~Rook(){}


/**
    Rook movement
    
    - Checks if it's moving in the same line or column 
    - Cannot change line and column at the same time

 */
template <typename P>
void Rook<P>::move(Board<P> *b, int xOrigin, int yOrigin, int xDestination, int yDestination){
    if(xOrigin != xDestination && yOrigin != yDestination){
        throw "Rook cannot move to that square";
    } 
    
    b->matrix[xOrigin][yOrigin] = emptyValue;
    b->matrix[xDestination][yDestination] = this->isWhite() ? this->getValue() : -1*this->getValue();
    
}