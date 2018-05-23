#pragma once

#include <string>
#include <iostream>
#include "Board.h"

using Coordinate=pairs;
using namespace std;

class Player{
        
    public:
        char myChar;
        Player(): myChar('.') {}
        Player(char sign): myChar(sign) {}
        
        char getChar() const{ return myChar;}
        const void setChar(char sign){ myChar = sign;}
    	virtual const string name() const = 0;
    	virtual const Coordinate play(const Board&) = 0;
};
