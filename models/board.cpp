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
    
    cout <<endl;
    cout << "     ";
    for(char l = 'A'; l <= 'I'; l++){
        if(l < 'I') cout << "  " << l << " ";
    }
    
    cout <<endl << "     ";
    for(int i = 0; i < 8; i++)    cout << " ---";
    cout <<endl;

    for(int i = 0; i < 8; i++){
        cout << "   ";
        cout << 8 - i;
        cout << " ";
        for(int j = 0; j < 8; j++){
            if(this->matrix[i][j] == 1) cout <<"| " << "P" << " ";
            else if(this->matrix[i][j] == 3) cout <<"| " <<"N" << " ";
            else if(this->matrix[i][j] == 4) cout <<"| " <<"B" << " ";
            else if(this->matrix[i][j] == 5) cout <<"| "  <<"R" << " ";
            else if(this->matrix[i][j] == 10) cout <<"| " <<"Q" << " ";
            else if(this->matrix[i][j] == 999) cout <<"| "  <<"K" << " ";
            else cout <<"| "  << "." << " ";

            if(j == 7)  cout << "|";
        }
        cout <<endl << " ";
        for(int i = 0; i <= 8; i++){
            if(i != 0)  cout << " ---";
            else cout << "    ";
        }    

        cout <<endl;
    }

    cout << "     ";
    for(char l = 'A'; l <= 'I'; l++){
        if(l < 'I') cout << "  " << l << " ";
    }
    cout <<endl;
}

