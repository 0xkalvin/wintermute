#include "rook.h"


Rook::Rook() : Piece('R', 5){}

Rook::~Rook(){}

void Rook::move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination){
    if(xOrigin != xDestination && yOrigin != yDestination) throw new string("Rook cannot move to that square.");
    
    if(b->matrix[xDestination][yDestination] == 0){
        b->matrix[xOrigin][yOrigin] = 0;
        b->matrix[xDestination][yDestination] = this->getValue();
    }
    
}