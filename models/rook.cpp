#include "rook.h"


Rook::Rook() : Piece(rookSymbol, rookValue){}

Rook::~Rook(){}

void Rook::move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination){
    if(xOrigin != xDestination && yOrigin != yDestination) throw new string("Rook cannot move to that square.");
    
    if(b->matrix[xDestination][yDestination] == emptyValue){
        b->matrix[xOrigin][yOrigin] = emptyValue;
        b->matrix[xDestination][yDestination] = this->getValue();
    }
    
}