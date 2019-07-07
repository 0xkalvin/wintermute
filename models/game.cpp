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
    int number;
    char letter;

    if(this->moves % 2 == 0) cout << "White to move." <<endl;
    else cout << "Black to move." <<endl;

    cout << "Enter the column letter " <<endl;
    cin >> letter;
    cout << "Enter the line number" <<endl;
    cin >> number;

    if(number != 1 && number != 2 && number != 3  && number != 4 
    && number != 5 && number != 6 && number != 7 && number != 8) throw new string("Line number must be between 1-8");

    if(letter != 'A' && letter != 'B' && letter != 'C'  && letter != 'D' 
    && letter != 'E' && letter != 'F' && letter != 'G' && letter != 'H') throw new string("column letter must be between A-H");
    
    if(this->moves % 2 == 0){
        
        this->white->move(letter, number);
    }
    else {
        this->black->move(letter, number);
    }

    this->moves += 1;

    cout << letter << number <<endl;
}

void Game::run(){  

    while(!this->isOver){
        this->print();
        this->input();
    }
}