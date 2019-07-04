#include <iostream>
#ifndef BOARD_H
#define BOARD_H

#include "pawn.h"

using namespace std;

class Board{
    private:
        int **matrix;

    public:
        Board();
        ~Board();
        void print();

};

#endif