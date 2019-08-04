#include "knight.h"

template <typename P>
Knight<P>::Knight(bool white) : Piece<P>(knightSymbol, knightValue, white, knightQuantity){}

template <typename P>
Knight<P>::~Knight(){}

/**
    Knight movement 
    
    - Verifies move by checking if its origin & destination squares forms a square triangle
    which has an area of √5  

 */
template <typename P>
void Knight<P>::move(Board<P> *b, int xOrigin, int yOrigin, int xDestination, int yDestination){
    double h = sqrt(pow(xDestination - xOrigin, 2) + pow(yDestination - yOrigin, 2));
    if(sqrt(5) != h) {
        throw "Knight cannot move to that square";
    }
    
    b->matrix[xOrigin][yOrigin] = emptyValue;
    b->matrix[xDestination][yDestination] = this->isWhite() ? this->getValue() : -1*this->getValue(); 

}