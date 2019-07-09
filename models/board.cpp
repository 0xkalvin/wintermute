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
        if(l < 'I') cout << "  " << BOLDBLUE <<l << " " << RESET;
    }
    
    cout <<endl << "     ";
    for(int i = 0; i < 8; i++)    cout << " ---";
    cout <<endl;

    for(int i = 0; i < 8; i++){
        cout << "   ";
        cout << MAGENTA << 8 - i << RESET;
        cout << " ";
        for(int j = 0; j < 8; j++){
            if(abs(this->matrix[i][j]) == pawnValue && this->matrix[i][j] > 0) cout <<"| " << BOLDWHITE << pawnSymbol << RESET <<" ";
            else if(abs(this->matrix[i][j]) == knightValue && this->matrix[i][j] > 0) cout <<"| " << BOLDWHITE << knightSymbol << RESET << " ";
            else if(abs(this->matrix[i][j]) == bishopValue && this->matrix[i][j] > 0) cout <<"| " << BOLDWHITE << bishopSymbol << RESET << " ";
            else if(abs(this->matrix[i][j]) == rookValue && this->matrix[i][j] > 0) cout <<"| "  << BOLDWHITE << rookSymbol << RESET << " ";
            else if(abs(this->matrix[i][j]) == queenValue && this->matrix[i][j] > 0) cout <<"| " << BOLDWHITE << queenSymbol << RESET << " ";
            else if(abs(this->matrix[i][j]) == kingValue && this->matrix[i][j] > 0) cout <<"| "  << BOLDWHITE << kingSymbol << RESET << " ";
            else if(abs(this->matrix[i][j]) == pawnValue && this->matrix[i][j] < 0) cout <<"| " << BOLDGREEN << pawnSymbol << RESET << " ";
            else if(abs(this->matrix[i][j]) == knightValue && this->matrix[i][j] < 0) cout <<"| " << BOLDGREEN << knightSymbol << RESET << " ";
            else if(abs(this->matrix[i][j]) == bishopValue && this->matrix[i][j] < 0) cout <<"| " << BOLDGREEN << bishopSymbol << RESET << " ";
            else if(abs(this->matrix[i][j]) == rookValue && this->matrix[i][j] < 0) cout <<"| "  << BOLDGREEN << rookSymbol << RESET << " ";
            else if(abs(this->matrix[i][j]) == queenValue && this->matrix[i][j] < 0) cout <<"| " << BOLDGREEN << queenSymbol << RESET << " ";
            else if(abs(this->matrix[i][j]) == kingValue && this->matrix[i][j] < 0) cout <<"| "  << BOLDGREEN << kingSymbol << RESET << " ";
            else cout <<"| "  << CYAN << emptySymbol << RESET <<" ";

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
        if(l < 'I') cout << "  " << BOLDBLUE << l << RESET <<" ";
    }
    cout <<endl;
}

