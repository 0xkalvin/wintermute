#ifndef PLAYER_H
#define PLAYER_H

#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

#include "board.h"

template <typename P>
class Game;

/**
    Player class 
    
    - Initializes each piece
    - Sets player color
    - Move verifications

 */
template <typename P>
class Player{
    private:
        Pawn<P> *pawn;
        Rook<P> *rook;
        Knight<P> *knight;
        Bishop<P> *bishop;
        Queen<P> *queen;
        King<P> *king;
        bool isWhite;
        friend class Game<P>;

    public:
        Player(Board<P> *b, char color);
        ~Player();
        void move(Board<P> *b, char letterOrigin, int numberOrigin, char letterDestination, int numberDestination);

};



#endif