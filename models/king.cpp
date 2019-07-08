#include "king.h"


King::King() : Piece('K', 999){}

King::~King(){}

void King::move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination){
    



    b->matrix[xOrigin][yOrigin] = 0;
    b->matrix[xDestination][yDestination] = this->getValue();
}