#ifndef SQUARE_H
#define SQUARE_H


template <typename P>
class Board;

/**
    Board square class 
    
    Stores square value, location and piece in it

 */
template <typename P>
class Square{
    private:
        int value;
        int coordinates[2];
        P piece;
        friend class Board<P>;
    
    public:
        Square();
        ~Square();
        int getValue();
        void setValue(int v);
        void setCoordinates(int x, int y);
        bool hasPiece();
        bool hasMoved();

        
};



#endif