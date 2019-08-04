#include "square.h"


template <typename P>
Square<P>::Square(){}

template <typename P>
Square<P>::~Square(){
    delete this->piece;
}

template <typename P>
void Square<P>::setValue(int v){
    this->value = v;
}

template <typename P>
void Square<P>::setCoordinates(int x, int y){
    this->coordinates[0] = x;
    this->coordinates[1] = y;
}

template <typename P>
int Square<P>::getValue(){
    return this->value;
}