#include "bishop.h"


template <typename P>
Bishop<P>::Bishop(bool white) : Piece<P>(bishopSymbol, bishopValue, white, bishopQuantity){}

template <typename P>
Bishop<P>::~Bishop(){}


/**
    Bishop movement 
    
    - Verifies if it's moving diagonally by checking Δx & Δy  

 */
template <typename P>
void Bishop<P>::move(Board<P> *b, int xOrigin, int yOrigin, int xDestination, int yDestination){

    int xDiff = abs(xOrigin - xDestination);
    int yDiff = abs(yOrigin - yDestination);

    if(xDiff != yDiff) throw "Bishop cannot move to that square";

    b->matrix[xOrigin][yOrigin] = emptyValue;
    b->matrix[xDestination][yDestination] = this->isWhite() ? this->getValue() : -1*this->getValue();
}