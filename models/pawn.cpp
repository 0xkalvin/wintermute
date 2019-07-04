#include "pawn.h"


Pawn::Pawn(){
    this->value = 1;
}

Pawn::~Pawn(){}


int Pawn::getValue(){
    return this->value;
}