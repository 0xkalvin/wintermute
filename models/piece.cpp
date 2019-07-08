#include "piece.h"


Piece::Piece(char s, int v, bool white){
    this->symbol = s;
    this->value = v;
    this->white = white;
}

Piece::~Piece(){}

char Piece::getSymbol(){
    return this->symbol;
}

int Piece::getValue(){
    return this->value;
}

bool Piece::isWhite(){
    return this->white;
}