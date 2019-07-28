#include "pawn.h"


Pawn::Pawn(bool white) : Piece(pawnSymbol, pawnValue, white, pawnQuantity){}

Pawn::~Pawn(){}


/**
    Pawn movements
    
    - Initial move controller (two squares forward allowed)
    - Move one square forward and capture diagonally
    - if it gets to the other side of the board, promotion 

 */
void Pawn::move(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination){ 

    cout << "VALOR: " << b->matrix[xDestination][yDestination] <<endl;

    if(( xOrigin == 6 && this->isWhite() ) || ( xOrigin == 1 && !this->isWhite()) ){
        if(abs(xDestination - xOrigin) > 2 || ( abs(yDestination - yOrigin) > 0 && abs(xDestination - xOrigin) == 2 )) 
            throw "Pawn cannot move to that square";
        if(abs(xDestination - xOrigin) == 1 && abs(yDestination - yOrigin) > 1)
            throw "Pawn cannot move to that square";
    }
    else{
        if(abs(xDestination - xOrigin) > 1 || abs(yDestination - yOrigin) > 1)
            throw "Pawn cannot move to that square";
    }

    // if pawn will not capture a piece, then it cannot move in diagonal
    if(b->matrix[xDestination][yDestination] == 0 && abs(yDestination - yOrigin) > 0)
        throw "Pawn cannot move to that square";
    
    // Pawn cannot move forward if there`s another piece right in the front of it
    if(b->matrix[xDestination][yDestination] != 0 && abs(xDestination - xOrigin) == 1 && abs(yDestination - yOrigin) == 0)
        throw "Pawn cannot move to that square, there's already a piece in it";

    int backwards = xDestination - xOrigin;
    if(this->isWhite() && backwards > 0)
        throw "Pawn cannot move backwards";
    else if(!this->isWhite() && backwards < 0)
        throw "Pawn cannot move backwards";

    if((!this->white && xDestination == 7) || (this->white && xDestination == 0)){
        this->promotion(b, xOrigin, yOrigin, xDestination, yDestination);
    }
    else{
        b->matrix[xOrigin][yOrigin] = emptyValue;
        b->matrix[xDestination][yDestination] = this->isWhite() ? this->getValue() : -1*this->getValue(); 
    }

}

/**
    
    Promotes pawn to another more valuable piece if it hits the oponent edge of the board

 */
void Pawn::promotion(Board *b, int xOrigin, int yOrigin, int xDestination, int yDestination){
    char piece;
    while(piece != rookSymbol && piece != knightSymbol && piece != bishopSymbol && piece != queenSymbol){
        cout << "Promote pawn to: (R, K, B, Q) " <<endl;
        cin >> piece;
    }

    int promotedValue;
    if(piece == rookSymbol) promotedValue = rookValue;
    else if(piece == knightSymbol) promotedValue = knightValue;
    else if(piece == bishopSymbol) promotedValue = bishopValue;
    else if(piece == queenSymbol) promotedValue = queenValue;
        
    b->matrix[xOrigin][yOrigin] = emptyValue;
    b->matrix[xDestination][yDestination] = this->isWhite() ? promotedValue : -1*promotedValue;
        
}