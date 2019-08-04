#include "piece.h"

template <typename P>
Piece<P>::Piece(char s, int v, bool white, int q){
    this->symbol = s;
    this->value = v;
    this->white = white;
    this->quantity = this->alive = q;
    this->moved = false;
}
template <typename P>
Piece<P>::~Piece(){}

template <typename P>
char Piece<P>::getSymbol(){
    return this->symbol;
}

template <typename P>
int Piece<P>::getValue(){
    return this->value;
}

template <typename P>
bool Piece<P>::isWhite(){
    return this->white;
}

template <typename P>
int Piece<P>::getQuantity(){
    return this->quantity;
}

template <typename P>
void Piece<P>::captured(){
    this->alive--;
}

template <typename P>
int Piece<P>::getAlive(){
    return this->alive;
}
