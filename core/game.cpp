#include <iostream>

#include "../models/pawn.h"

using namespace std;

int main()
{

    Pawn *p1 = new Pawn();

    cout << p1->getValue() <<endl;

    return 0;
}