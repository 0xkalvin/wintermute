#include "bishop.h"


Bishop::Bishop() : Piece(bishopSymbol, bishopValue){}

Bishop::~Bishop(){}

void Bishop::move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination){




    b->matrix[xOrigin][yOrigin] = emptyValue;
    b->matrix[xDestination][yDestination] = this->getValue();
}