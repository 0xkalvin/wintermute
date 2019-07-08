#include "pawn.h"


Pawn::Pawn() : Piece('P', 1){}

Pawn::~Pawn(){}

void Pawn::move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination){
    // check line
    if(abs(xDestination - xOrigin) > 2 || abs(xDestination - xOrigin) < 0) throw new string("Pawn cannot move to that square.");
    // check column
    if(abs(yDestination - yOrigin) > 1 || abs(yDestination - yOrigin) < 0 ) throw new string("Pawn cannot move to that square.");

    b->matrix[xOrigin][yOrigin] = 0;
    b->matrix[xDestination][yDestination] = this->getValue();

}