#include "piece.h"


Piece::Piece(char s, int v, bool white, int q){
    this->symbol = s;
    this->value = v;
    this->white = white;
    this->quantity = this->alive = q;
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

int Piece::getQuantity(){
    return this->quantity;
}

void Piece::captured(){
    this->alive--;
}

int Piece::getAlive(){
    return this->alive;
}