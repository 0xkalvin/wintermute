#include "square.h"

Square::Square(){
    this->value = 0;
    this->piece = NULL;
    this->occupied = false;
}

Square::~Square(){
    delete this->piece;
}

bool Square::isOccupied(){
    return this->occupied;
}

int Square::getValue(){
    return this->value;
}

void Square::placePiece(Piece *p){
    if(this->value != 0) return;
}   