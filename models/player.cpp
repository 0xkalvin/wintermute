#include "player.h"

/**
    
    Setting color and pieces

 */
Player::Player(Board *b, char color)
{
    this->isWhite = color == 'B' ? false : true;
    this->pawn = new Pawn(this->isWhite);
    this->rook = new Rook(this->isWhite);
    this->knight = new Knight(this->isWhite);
    this->bishop = new Bishop(this->isWhite);
    this->queen = new Queen(this->isWhite);
    this->king = new King(this->isWhite);

    for (int i = 0; i < 8; i++)
    {
        // BLACK
        if (!this->isWhite)
        {
            b->matrix[1][i] = -1*this->pawn->getValue();
            if (i == 0 || i == 7)
                b->matrix[0][i] = -1*this->rook->getValue();
            else if (i == 1 || i == 6)
                b->matrix[0][i] = -1*this->knight->getValue();
            else if (i == 2 || i == 5)
                b->matrix[0][i] = -1*this->bishop->getValue();
            else if (i == 3)
                b->matrix[0][i] = -1*this->queen->getValue();
            else if (i == 4)
                b->matrix[0][i] = -1*this->king->getValue();
        }
        // WHITE
        else
        {   
            b->matrix[6][i] = this->pawn->getValue();
            if (i == 0 || i == 7)
                b->matrix[7][i] = this->rook->getValue();
            else if (i == 1 || i == 6)
                b->matrix[7][i] = this->knight->getValue();
            else if (i == 2 || i == 5)
                b->matrix[7][i] = this->bishop->getValue();
            else if (i == 3)
                b->matrix[7][i] = this->queen->getValue();
            else if (i == 4)
                b->matrix[7][i] = this->king->getValue();
        }
    }
}

Player::~Player()
{
    delete this->bishop;
    delete this->pawn;
    delete this->rook;
    delete this->king;
    delete this->knight;
    delete this->queen;
}

/**
    
    - Convert player input notation to matrix coordinates
    - Based on the square value, move the right piece

 */
void Player::move(Board *b, char letterOrigin, int numberOrigin, char letterDestination, int numberDestination){
    int columnOrigin, lineOrigin, columnDestination, lineDestination;
    bool response;

    lineOrigin = 8 - numberOrigin;
    lineDestination = 8 - numberDestination;
    
    if(letterOrigin == 'A') columnOrigin = 0;
    else if(letterOrigin == 'B') columnOrigin = 1;
    else if(letterOrigin == 'C') columnOrigin = 2;
    else if(letterOrigin == 'D') columnOrigin = 3;
    else if(letterOrigin == 'E') columnOrigin = 4;
    else if(letterOrigin == 'F') columnOrigin = 5;
    else if(letterOrigin == 'G') columnOrigin = 6;
    else if(letterOrigin == 'H') columnOrigin = 7;

    if(letterDestination == 'A') columnDestination = 0;
    else if(letterDestination == 'B') columnDestination = 1;
    else if(letterDestination == 'C') columnDestination = 2;
    else if(letterDestination == 'D') columnDestination = 3;
    else if(letterDestination == 'E') columnDestination = 4;
    else if(letterDestination == 'F') columnDestination = 5;
    else if(letterDestination == 'G') columnDestination = 6;
    else if(letterDestination == 'H') columnDestination = 7;


    // Controls turns and some impossible moves
    if(b->matrix[lineDestination][columnDestination] > 0 && this->isWhite)
        throw "There`s already a white piece on that square";
    
    else if(b->matrix[lineDestination][columnDestination] < 0 && !this->isWhite)    
        throw "There`s already a black piece on that square";

    if(b->matrix[lineOrigin][columnOrigin] > 0 && !this->isWhite)
        throw "Black cannot move white piece";
    
    else if(b->matrix[lineOrigin][columnOrigin] < 0 && this->isWhite)    
        throw "White cannot move black piece";
    
    int destinationValue = b->matrix[lineDestination][columnDestination];

    if(abs(b->matrix[lineOrigin][columnOrigin]) == this->pawn->getValue())
        this->pawn->move(b, lineOrigin, columnOrigin, lineDestination, columnDestination);
    else if(abs(b->matrix[lineOrigin][columnOrigin]) == this->rook->getValue()) 
        this->rook->move(b, lineOrigin, columnOrigin, lineDestination, columnDestination);
    else if(abs(b->matrix[lineOrigin][columnOrigin]) == this->knight->getValue()) 
        this->knight->move(b, lineOrigin, columnOrigin, lineDestination, columnDestination);
    else if(abs(b->matrix[lineOrigin][columnOrigin]) == this->bishop->getValue()) 
        this->bishop->move(b, lineOrigin, columnOrigin, lineDestination, columnDestination);
    else if(abs(b->matrix[lineOrigin][columnOrigin]) == this->queen->getValue()) 
        this->queen->move(b, lineOrigin, columnOrigin, lineDestination, columnDestination);
    else if(abs(b->matrix[lineOrigin][columnOrigin]) == this->king->getValue()) 
        this->king->move(b, lineOrigin, columnOrigin, lineDestination, columnDestination);
    else    throw "There`s no piece on that square";


    // Controls the number of each captured piece and then uses it to show all off-board pieces
    if(destinationValue != 0){
        if(abs(destinationValue) == pawnValue)
            this->pawn->captured();
        else if(abs(destinationValue) == knightValue)
            this->knight->captured();
        else if(abs(destinationValue) == bishopValue)
            this->bishop->captured();
        else if(abs(destinationValue) == rookValue)
            this->rook->captured();
        else if(abs(destinationValue) == queenValue)
            this->queen->captured();
    } 
    
}