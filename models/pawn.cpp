#include "pawn.h"


Pawn::Pawn(bool white) : Piece(pawnSymbol, pawnValue, white){}

Pawn::~Pawn(){}

void Pawn::move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination){ 
    if(( xOrigin == 6 && this->isWhite() ) || ( xOrigin == 1 && !this->isWhite()) ){
        if(abs(xDestination - xOrigin) > 2 || ( abs(yDestination - yOrigin) > 0 && abs(xDestination - xOrigin) == 2 )) 
            throw "Pawn cannot move to that square";
        if(abs(xDestination - xOrigin) == 1 && abs(yDestination - yOrigin) > 1)
            throw "Pawn cannot move to that square";
    }
    else{
        if(abs(xDestination - xOrigin) > 1 || abs(yDestination - yOrigin) > 1)
            throw "Pawn cannot move to that square";
    }



    b->matrix[xOrigin][yOrigin] = emptyValue;
    b->matrix[xDestination][yDestination] = this->isWhite() ? this->getValue() : -1*this->getValue(); 
}