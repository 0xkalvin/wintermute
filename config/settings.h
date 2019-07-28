#ifndef GAME_CONSTANTS
#define GAME_CONSTANTS 

#include <math.h> 
#include <string>

/**
    Game Constants 

    - Values and symbols for each piece. They will be used as identifiers and to create scores
    - Values for shell text colors

 */
const int emptyValue = 0;
const char emptySymbol = '.';

const int pawnValue = 1;
const int rookValue = 5;
const int knightValue = 3;
const int bishopValue = 4;
const int queenValue = 10;
const int kingValue = 999;


const char pawnSymbol = 'P';
const char rookSymbol = 'R';
const char knightSymbol = 'N';
const char bishopSymbol = 'B';
const char queenSymbol = 'Q';
const char kingSymbol = 'K';

const int pawnQuantity = 8;
const int rookQuantity = 2;
const int knightQuantity = 2;
const int bishopQuantity = 2;
const int queenQuantity = 1;
const int kingQuantity = 1;


#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"

#endif