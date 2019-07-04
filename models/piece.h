#include <iostream>
#ifndef PIECE_H
#define PIECE_H

using namespace std;

class Piece{
    private:
        char symbol;
        int value;
        bool alive;
        int x_position;
        int y_position;
    
    public:
        Piece(char s, int v);
        ~Piece();
        char getSymbol();
        int getValue();
        bool isAlive();
        void move();
};



#endif