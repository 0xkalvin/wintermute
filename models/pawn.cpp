#include "pawn.h"


Pawn::Pawn(bool white) : Piece(pawnSymbol, pawnValue, white){}

Pawn::~Pawn(){}

void Pawn::move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination){
    // check line
    if(abs(xDestination - xOrigin) > 2 || abs(xDestination - xOrigin) < 0){
        throw "Pawn cannot move to that square";
    } 
    // check column
    if(abs(yDestination - yOrigin) > 1 || abs(yDestination - yOrigin) < 0 ){
        throw "Pawn cannot move to that square";
    } 

    b->matrix[xOrigin][yOrigin] = emptyValue;
    b->matrix[xDestination][yDestination] = this->isWhite() ? this->getValue() : -1*this->getValue(); 
}