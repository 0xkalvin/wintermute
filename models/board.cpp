#include "board.h"


/*
    Used notation for pieces:

        P P P P P P P P 
        R N B Q K B N R

 */

Board::Board(){
    this->matrix = (int**)malloc(8 * sizeof(int*));
    for(int i = 0; i < 8; i++){
        this->matrix[i] = (int*)malloc(8 * sizeof(int));
        for(int j = 0; j < 8; j++){
            matrix[i][j] = 0;
        }
    }
}

Board::~Board(){
    for(int i = 0 ; i < 8 ; i++ )   free(this->matrix[i]); 
    free(this->matrix);
}

void Board::print(){

    for(int i = 0; i < 8; i++){
        cout << " |  ";
        cout << i + 1;
        cout << "  |";
        for(int j = 0; j < 8; j++){
            if(this->matrix[i][j] == 1) cout << "   " <<"P";
            else if(this->matrix[i][j] == 3) cout << "   " <<"N";
            else if(this->matrix[i][j] == 4) cout << "   " <<"B";
            else if(this->matrix[i][j] == 5) cout << "   " <<"R";
            else if(this->matrix[i][j] == 10) cout << "   " <<"Q";
            else if(this->matrix[i][j] == 999) cout << "   " <<"K";
            else cout << "   " <<"0";
        }
        cout <<endl;
    }
    cout << "         ";

    for(char l = 'a'; l <= 'i'; l++){
        cout << "  ";
        if(l < 'i') cout << l;
        cout << " ";
    }
    
    cout <<endl;
}

void Board::init(){
    this->pawn = new Pawn();
    this->rook = new Rook();
    this->knight = new Knight();
    this->bishop = new Bishop();
    this->queen = new Queen();
    this->king = new King();
    
    for(int i = 0; i < 8; i++){  
        // BLACK
        this->matrix[1][i] = this->pawn->getValue();
        if(i == 0 || i == 7)this->matrix[0][i] = this->rook->getValue();
        else if(i == 1 || i == 6)this->matrix[0][i] = this->knight->getValue();
        else if(i == 2 || i == 5)this->matrix[0][i] = this->bishop->getValue();
        else if(i == 3)this->matrix[0][i] = this->queen->getValue();
        else if(i == 4)this->matrix[0][i] = this->king->getValue();
        // WHITE
        this->matrix[6][i] = this->pawn->getValue();
        if(i == 0 || i == 7)this->matrix[7][i] = this->rook->getValue();
        else if(i == 1 || i == 6)this->matrix[7][i] = this->knight->getValue();
        else if(i == 2 || i == 5)this->matrix[7][i] = this->bishop->getValue();
        else if(i == 3)this->matrix[7][i] = this->queen->getValue();
        else if(i == 4)this->matrix[7][i] = this->king->getValue();
    }
 
}