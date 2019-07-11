#include "knight.h"


Knight::Knight(bool white) : Piece(knightSymbol, knightValue, white, knightQuantity){}

Knight::~Knight(){}

void Knight::move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination){
    double h = sqrt(pow(xDestination - xOrigin, 2) + pow(yDestination - yOrigin, 2));
    if(sqrt(5) != h) {
        throw "Knight cannot move to that square";
    }
    
    b->matrix[xOrigin][yOrigin] = emptyValue;
    b->matrix[xDestination][yDestination] = this->isWhite() ? this->getValue() : -1*this->getValue(); 

}