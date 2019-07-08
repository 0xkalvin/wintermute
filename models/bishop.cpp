#include "bishop.h"


Bishop::Bishop(bool white) : Piece(bishopSymbol, bishopValue, white){}

Bishop::~Bishop(){}

void Bishop::move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination){




    b->matrix[xOrigin][yOrigin] = emptyValue;
    b->matrix[xDestination][yDestination] = this->isWhite() ? this->getValue() : -1*this->getValue();
}