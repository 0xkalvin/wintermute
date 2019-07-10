#include "bishop.h"


Bishop::Bishop(bool white) : Piece(bishopSymbol, bishopValue, white){}

Bishop::~Bishop(){}

void Bishop::move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination){

    int xDiff = abs(xOrigin - xDestination);
    int yDiff = abs(yOrigin - yDestination);

    if(xDiff != yDiff) throw "Bishop cannot move to that square";

    b->matrix[xOrigin][yOrigin] = emptyValue;
    b->matrix[xDestination][yDestination] = this->isWhite() ? this->getValue() : -1*this->getValue();
}