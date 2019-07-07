#ifndef BOARD_H
#define BOARD_H

#include <iostream>

using namespace std;

class Player;
class Pawn;

class Board{
    private:
        int **matrix;
        friend class Player;
        friend class Pawn;

    public:
        Board();
        ~Board();
        void print();

};

#endif