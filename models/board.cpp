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
            cout << "   " <<this->matrix[i][j];
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