#include "game.h"


Game::Game(){
    this->isOver = false;
    this->moves = 0;
    this->board = new Board();
    this->black = new Player(this->board, 'B');
    this->white = new Player(this->board, 'W');
}

Game::~Game(){
    delete this->board;   
}

void Game::print(){  
    this->board->print(); 
}

void Game::input(){
    int numberOrigin, numberDestination;
    char letterOrigin, letterDestination;
    bool isMoveInvalid = true;



    while(isMoveInvalid){
        if(this->moves % 2 == 0) cout << "White to move." <<endl;
        else cout << "Black to move." <<endl;

        cout << "which piece do you want to move?" <<endl;
        cout << "Enter the column letter " <<endl;
        cin >> letterOrigin;
        cout << "Enter the line number" <<endl;
        cin >> numberOrigin;

        cout << "To where do you want to move it?" <<endl;
        cout << "Enter the column letter " <<endl;
        cin >> letterDestination;
        cout << "Enter the line number" <<endl;
        cin >> numberDestination;

        if(numberOrigin != 1 && numberOrigin != 2 && numberOrigin != 3  && numberOrigin != 4 
        && numberOrigin != 5 && numberOrigin != 6 && numberOrigin != 7 && numberOrigin != 8
        && numberDestination != 1 && numberDestination != 2 && numberDestination != 3  && numberDestination != 4 
        && numberDestination != 5 && numberDestination != 6 && numberDestination != 7 
        && numberDestination != 8) cout << "Line number must be between 1-8" <<endl;

        if(letterOrigin != 'A' && letterOrigin != 'B' && letterOrigin != 'C'  && letterOrigin != 'D' 
        && letterOrigin != 'E' && letterOrigin != 'F' && letterOrigin != 'G' && letterOrigin != 'H'
        && letterDestination != 'A' && letterDestination != 'B' && letterDestination != 'C'  
        && letterDestination != 'D' && letterDestination != 'E' && letterDestination != 'F' 
        && letterDestination != 'G' && letterDestination != 'H') cout << "column letter must be between A-H" << endl;
        
        if(this->moves % 2 == 0){
            
            isMoveInvalid = this->white->move(this->board, letterOrigin, numberOrigin, letterDestination, numberDestination, isMoveInvalid);
        }
        else {
            isMoveInvalid = this->black->move(this->board, letterOrigin, numberOrigin, letterDestination, numberDestination, isMoveInvalid);
        }
    }

    this->moves += 1;

    cout << letterOrigin << numberOrigin <<endl;
}

void Game::run(){  

    while(!this->isOver){
        this->print();
        this->input();
    }
}