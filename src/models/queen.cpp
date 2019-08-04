#include "queen.h"

template <typename P>
Queen<P>::Queen(bool white) : Piece<P>(queenSymbol, queenValue, white, queenQuantity){}

template <typename P>
Queen<P>::~Queen(){}

/**
    Queen move
    
    - Basically, the overlay of rook & bishop movement

 */
template <typename P>
void Queen<P>::move(Board<P> *b, int xOrigin, int yOrigin, int xDestination, int yDestination){
    int xDiff = abs(xOrigin - xDestination);
    int yDiff = abs(yOrigin - yDestination);

    if(xDiff != yDiff && xOrigin != xDestination && yOrigin != yDestination) throw "Queen cannot move to that square";
    
    b->matrix[xOrigin][yOrigin] = emptyValue;
    b->matrix[xDestination][yDestination] = this->isWhite() ? this->getValue() : -1*this->getValue();
}