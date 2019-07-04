#include "game.h"


Game::Game(){
    this->board = new Board();
    this->board->init();
}

Game::~Game(){   
}

void Game::print(){  
    this->board->print(); 
}