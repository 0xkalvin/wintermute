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
    delete this->black ;
    delete this->white ;
}

/**
    
    To show both black & white captured pieces,
    compares number of each active piece on the board
    and each piece initial quantity 

 */
void Game::showCapturedPieces(){
    int deadPawnsWhite = this->white->pawn->getQuantity() - this->white->pawn->getAlive();
    int deadRooksWhite = this->white->rook->getQuantity() - this->white->rook->getAlive();
    int deadKnightsWhite = this->white->knight->getQuantity() - this->white->knight->getAlive();
    int deadBishopsWhite = this->white->bishop->getQuantity() - this->white->bishop->getAlive();
    int deadQueenWhite = this->white->queen->getQuantity() - this->white->queen->getAlive();
    
    cout << endl << BOLDGREEN << "   CAPTURED BLACK: " << RESET;
    int i;
    for(i = 0; i < deadPawnsWhite; i++) cout << BOLDGREEN << pawnSymbol << RESET << " ";
    for(i = 0; i < deadRooksWhite; i++) cout << BOLDGREEN << rookSymbol << RESET << " ";
    for(i = 0; i < deadKnightsWhite; i++) cout << BOLDGREEN << knightSymbol << RESET << " ";
    for(i = 0; i < deadBishopsWhite; i++) cout << BOLDGREEN << bishopSymbol << RESET << " ";
    for(i = 0; i < deadQueenWhite; i++) cout << BOLDGREEN << queenSymbol << RESET << " ";

    int deadPawnsBlack = this->black->pawn->getQuantity() - this->black->pawn->getAlive();
    int deadRooksBlack= this->black->rook->getQuantity() - this->black->rook->getAlive();
    int deadKnightsBlack = this->black->knight->getQuantity() - this->black->knight->getAlive();
    int deadBishopsBlack = this->black->bishop->getQuantity() - this->black->bishop->getAlive();
    int deadQueenBlack= this->black->queen->getQuantity() - this->black->queen->getAlive();

    cout << endl << BOLDWHITE<< "   CAPTURED WHITE: " << RESET;
    for(i = 0; i < deadPawnsBlack; i++) cout << BOLDWHITE << pawnSymbol << RESET << " ";
    for(i = 0; i < deadRooksBlack; i++) cout << BOLDWHITE << rookSymbol << RESET << " ";
    for(i = 0; i < deadKnightsBlack; i++) cout << BOLDWHITE << knightSymbol << RESET << " ";
    for(i = 0; i < deadBishopsBlack; i++) cout << BOLDWHITE << bishopSymbol << RESET << " ";
    for(i = 0; i < deadQueenBlack; i++) cout << BOLDWHITE << queenSymbol << RESET << " ";

    cout <<endl;
}

/**
    Game interface
 */
void Game::print(){  
    cout << MAGENTA <<"                WINTERMUTE" << RESET <<endl;
    this->board->print();
    
    this->showCapturedPieces();

    cout << "Number of moves: " << this->moves <<endl;
    
    if(this->moves != 0)
        cout << this->lastMove[0] << this->lastMove[1] << " -> " << this->lastMove[2] << this->lastMove[3] <<endl;
}

/**
    
    Takes user input & validates it 
    if not valid, keeps asking for a valid move.
    Controls white and black turn.

 */
void Game::input(){
    int numberOrigin, numberDestination;
    char letterOrigin, letterDestination;
    bool isMoveValid = false;



    while(!isMoveValid){
        try{
            if(this->moves % 2 == 0) cout << "White to move." <<endl;
            else cout <<"Black to move." <<endl;

            cout << "which piece do you want to move?" <<endl;
            string input;
            getline (cin, input);
            if(input.length() != 2) throw "Invalid input";

            letterOrigin = toupper(input[0]);
            numberOrigin = (int)input[1] - 48;

            cout << "To where do you want to move it?" <<endl;
            getline (cin, input);
            if(input.length() != 2) throw "Invalid input";
            
            letterDestination = toupper(input[0]);
            numberDestination = (int)input[1] - 48;

            if(numberOrigin != 1 && numberOrigin != 2 && numberOrigin != 3  && numberOrigin != 4 
            && numberOrigin != 5 && numberOrigin != 6 && numberOrigin != 7 && numberOrigin != 8
            && numberDestination != 1 && numberDestination != 2 && numberDestination != 3  && numberDestination != 4 
            && numberDestination != 5 && numberDestination != 6 && numberDestination != 7 
            && numberDestination != 8) throw "Line number must be between 1-8";

            if(letterOrigin != 'A' && letterOrigin != 'B' && letterOrigin != 'C'  && letterOrigin != 'D' 
            && letterOrigin != 'E' && letterOrigin != 'F' && letterOrigin != 'G' && letterOrigin != 'H'
            && letterDestination != 'A' && letterDestination != 'B' && letterDestination != 'C'  
            && letterDestination != 'D' && letterDestination != 'E' && letterDestination != 'F' 
            && letterDestination != 'G' && letterDestination != 'H') throw "column letter must be between A-H";
            
            if(this->moves % 2 == 0){
                
                this->white->move(this->board, letterOrigin, numberOrigin, letterDestination, numberDestination);
            }
            else {
                this->black->move(this->board, letterOrigin, numberOrigin, letterDestination, numberDestination);
            }
            isMoveValid = true;
        }
        catch(const char *const error){
            cout << "Error: " << error << endl;
        }

    }

    this->moves += 1;
    this->lastMove[0] = letterOrigin;
    this->lastMove[1] = numberOrigin + '0';
    this->lastMove[2] = letterDestination;
    this->lastMove[3] = numberDestination + '0';
    cout << letterOrigin << numberOrigin <<endl;
}

void Game::run(){  

    while(!this->isOver){
        system("clear");
        this->print();
        this->input();
    }
}