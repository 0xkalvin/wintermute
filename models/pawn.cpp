#include "pawn.h"


Pawn::Pawn(bool white) : Piece(pawnSymbol, pawnValue, white, pawnQuantity){}

Pawn::~Pawn(){}

void Pawn::move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination){ 

    cout << "VALOR: " << b->matrix[xDestination][yDestination] <<endl;

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

    // if pawn will not capture a piece, then it cannot move in diagonal
    if(b->matrix[xDestination][yDestination] == 0 && abs(yDestination - yOrigin) > 0)
        throw "Pawn cannot move to that square";
    
    // Pawn cannot move forward if there`s another piece right in the front of it
    if(b->matrix[xDestination][yDestination] != 0 && abs(xDestination - xOrigin) == 1 && abs(yDestination - yOrigin) == 0)
        throw "Pawn cannot move to that square, there's already a piece in it";

    int backwards = xDestination - xOrigin;
    if(this->isWhite() && backwards > 0)
        throw "Pawn cannot move backwards";
    else if(!this->isWhite() && backwards < 0)
        throw "Pawn cannot move backwards";

    b->matrix[xOrigin][yOrigin] = emptyValue;
    b->matrix[xDestination][yDestination] = this->isWhite() ? this->getValue() : -1*this->getValue(); 
}