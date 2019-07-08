#include "pawn.h"


Pawn::Pawn(bool white) : Piece(pawnSymbol, pawnValue, white){}

Pawn::~Pawn(){}

bool Pawn::move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination){
    // check line
    if(abs(xDestination - xOrigin) > 2 || abs(xDestination - xOrigin) < 0){
        cout << "Pawn cannot move to that square" <<endl;
        return false;
    } 
    // check column
    if(abs(yDestination - yOrigin) > 1 || abs(yDestination - yOrigin) < 0 ){
        cout << "Pawn cannot move to that square" <<endl;
        return false;
    } 

    b->matrix[xOrigin][yOrigin] = emptyValue;
    b->matrix[xDestination][yDestination] = this->isWhite() ? this->getValue() : -1*this->getValue(); 
    return true;
}