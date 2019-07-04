#include <iostream>
#ifndef PAWN_H
#define PAWN_H


class Pawn{
    private:
        int value;
        bool alive;

    public:
        Pawn();
        ~Pawn();
        bool isAlive();
        int getValue();

};

#endif