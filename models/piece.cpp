#include "piece.h"


Piece::Piece(char s, int v){
    this->symbol = s;
    this->value = v;
    // this->x_position = x_pos;
    // this->y_position = y_pos;
}

Piece::~Piece(){}

char Piece::getSymbol(){
    return this->symbol;
}

int Piece::getValue(){
    return this->value;
}