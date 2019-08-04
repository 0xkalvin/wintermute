#include "king.h"

template <typename P>
King<P>::King(bool white) : Piece<P>(kingSymbol, kingValue, white, kingQuantity){}

template <typename P>
King<P>::~King(){}

/* 
    
*/
template <typename P>
void King<P>::castle(Board<P> *b, int xOrigin, int yOrigin, int xDestination, int yDestination){

    // king side 
    if(yDestination - yOrigin == 2 && b->matrix[xDestination][yDestination - 1] == emptyValue
    && b->matrix[xDestination][yDestination] == emptyValue && abs(b->matrix[xDestination][yDestination+1]) == rookValue){
        b->matrix[xDestination][yDestination] = this->isWhite() ? kingValue : -1*kingValue;
        b->matrix[xDestination][yDestination - 1] = this->isWhite() ? rookValue : -1*rookValue;
        b->matrix[xDestination][yDestination - 2] = emptyValue;
        b->matrix[xDestination][yDestination + 1] = emptyValue;
    }
    // queen side
    if(yDestination - yOrigin == -2 && b->matrix[xDestination][yDestination + 1] == emptyValue
    && b->matrix[xDestination][yDestination] == emptyValue && abs(b->matrix[xDestination][yDestination-2]) == rookValue){
        b->matrix[xDestination][yDestination] = this->isWhite() ? kingValue : -1*kingValue;
        b->matrix[xDestination][yDestination + 1] = this->isWhite() ? rookValue : -1*rookValue;
        b->matrix[xDestination][yDestination + 2] = emptyValue;
        b->matrix[xDestination][yDestination - 2] = emptyValue;
    }

}

/**
    King movement 
    
    - Verifies move by checking if it's moving only a square unit

 */
template <typename P>
void King<P>::move(Board<P> *b, int xOrigin, int yOrigin, int xDestination, int yDestination){
    int xDiff = abs(xOrigin - xDestination);
    int yDiff = abs(yOrigin - yDestination);

    // To see if its a castle movement, checks if the absolute value of Δy is 2
    // also checks if king has already moved
    if(!this->moved && xDestination == xOrigin && abs(yDestination - yOrigin) == 2){
        this->castle(b, xOrigin, yOrigin, xDestination, yDestination);
    }
    else{
         if((abs(xDestination - xOrigin) > 1 || abs(yDestination - yOrigin) > 1) || 
            (xDiff != yDiff && xOrigin != xDestination && yOrigin != yDestination))
                throw "King cannot move to that square";
                
            b->matrix[xOrigin][yOrigin] = emptyValue;
            b->matrix[xDestination][yDestination] = this->isWhite() ? this->getValue() : -1*this->getValue();
    }

    if(!this->moved)    this->moved = true;
}