#include "knight.h"


Knight::Knight() : Piece(knightSymbol, knightValue){}

Knight::~Knight(){}

void Knight::move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination){
    if(abs(xDestination - xOrigin) > 2 || abs(xDestination - xOrigin) < 0) throw new string("Pawn cannot move to that square.");
    
    if(abs(yDestination - yOrigin) > 1 || abs(yDestination - yOrigin) < 0 ) throw new string("Pawn cannot move to that square.");

    
    b->matrix[xOrigin][yOrigin] = emptyValue;
    b->matrix[xDestination][yDestination] = this->getValue();

}