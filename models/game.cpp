#include "game.h"


Game::Game(){
    this->board = new Board();
}

Game::~Game(){   
}

void Game::print(){  
    this->board->print(); 
}