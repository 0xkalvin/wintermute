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
    cout << "                CHESS GAME" <<endl;
    this->board->print();
    cout << "Number of moves: " << this->moves <<endl;
    // cout << "Last move: " << this->lastMove <<endl;
}

void Game::input(){
    int numberOrigin, numberDestination;
    char letterOrigin, letterDestination;
    bool isMoveValid = false;



    while(!isMoveValid){
        try{
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
            && numberDestination != 8) throw "Line number must be between 1-8";

            if(letterOrigin != 'A' && letterOrigin != 'B' && letterOrigin != 'C'  && letterOrigin != 'D' 
            && letterOrigin != 'E' && letterOrigin != 'F' && letterOrigin != 'G' && letterOrigin != 'H'
            && letterDestination != 'A' && letterDestination != 'B' && letterDestination != 'C'  
            && letterDestination != 'D' && letterDestination != 'E' && letterDestination != 'F' 
            && letterDestination != 'G' && letterDestination != 'H') throw "column letter must be between A-H";
            
            if(this->moves % 2 == 0){
                
                this->white->move(this->board, letterOrigin, numberOrigin, letterDestination, numberDestination);
            }
            else {
                this->black->move(this->board, letterOrigin, numberOrigin, letterDestination, numberDestination);
            }
            isMoveValid = true;
        }
        catch(const char *const error){
            cout << "Error: " << error << endl;
        }

    }

    this->moves += 1;
    // this->lastMove[0]  = letterDestination;
    // this->lastMove[1]  = '0' + numberDestination; 
    cout << letterOrigin << numberOrigin <<endl;
}

void Game::run(){  

    while(!this->isOver){
        this->print();
        this->input();
    }
}