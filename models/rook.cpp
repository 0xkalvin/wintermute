#include "rook.h"


Rook::Rook(bool white) : Piece(rookSymbol, rookValue, white){}

Rook::~Rook(){}

bool Rook::move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination){
    if(xOrigin != xDestination && yOrigin != yDestination){
        cout << "Rook cannot move to that square" <<endl;
        return false;
    } 
    
    b->matrix[xOrigin][yOrigin] = emptyValue;
    b->matrix[xDestination][yDestination] = this->isWhite() ? this->getValue() : -1*this->getValue();
    return true; 
    
}