#include "game.h"


Game::Game(){
    this->board = new Board();
    //this->board->init();
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
    int x, y;
    cout << "Enter the line " <<endl;
    cin >> x;
    cout << "Enter the column" <<endl;
    cin >> y;
}

void Game::run(){  
    this->print();
}