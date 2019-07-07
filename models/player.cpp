#include "player.h"

Player::Player(Board *b, char color)
{
    this->pawn = new Pawn();
    this->rook = new Rook();
    this->knight = new Knight();
    this->bishop = new Bishop();
    this->queen = new Queen();
    this->king = new King();

    for (int i = 0; i < 8; i++)
    {
        // BLACK
        if (color == 'B')
        {
            b->matrix[1][i] = this->pawn->getValue();
            if (i == 0 || i == 7)
                b->matrix[0][i] = this->rook->getValue();
            else if (i == 1 || i == 6)
                b->matrix[0][i] = this->knight->getValue();
            else if (i == 2 || i == 5)
                b->matrix[0][i] = this->bishop->getValue();
            else if (i == 3)
                b->matrix[0][i] = this->queen->getValue();
            else if (i == 4)
                b->matrix[0][i] = this->king->getValue();
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


void Player::move(){
    
}