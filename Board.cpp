#ifndef _BOARD_CPP
#define _BOARD_CPP
#include "Board.h"
#endif

Board :: Board (int size){
    boardSize = size;
    alloc();
}

Board :: Board(Board& other){
    this-> boardSize = other.boardSize;
    alloc();
    for(int rows = 0; rows < (this-> boardSize); rows++)
    	 for(int columns = 0; columns < (this-> boardSize); columns++)
    	       (this-> gameBoard[rows][columns]) = other.gameBoard[rows][columns].get_sign();
}

Board :: ~Board(){
    dlloc();
}

void Board :: dlloc(){
    for(int i = 0; i < boardSize; i++)
		delete [] gameBoard[i];
	delete [] gameBoard; 
}

void Board :: alloc(){
	gameBoard = new place*[boardSize];
	for(int i = 0; i < boardSize; i++) gameBoard[i] = new place[boardSize];
}

void Board :: fill(char symbol){
        for(int rows = 0; rows < (this-> boardSize); rows++)
    	    for(int columns = 0; columns < (this-> boardSize); columns++)
    	       (this-> gameBoard[rows][columns]) = symbol;
}

place& Board :: operator[] (const pairs index){
    if(index.first >= boardSize || index.second >= boardSize){
      IllegalCoordinateException coordinate;
      coordinate.set_first(index.first);
      coordinate.set_second(index.second);
      throw coordinate;
    } 
    if(index.first < 0 || index.second < 0){
        IllegalCoordinateException coordinate;
        coordinate.set_first(index.first);
        coordinate.set_second(index.second);
        throw coordinate;
    }
    return gameBoard[index.first][index.second];
}

Board& Board ::operator= (Board& other){
    if(this == &other) return *this;
    dlloc();
    boardSize = other.boardSize;
    gameBoard = new place*[boardSize];
    for(int rows = 0; rows < (this-> boardSize); rows++){
	    gameBoard[rows] = new place[boardSize];
    	    for(int columns = 0; columns < (this-> boardSize); columns++)
    	       (this-> gameBoard[rows][columns]) = other.gameBoard[rows][columns];}
    return *this;
}

char Board :: operator= (char symbol){
    if(symbol == '.'){ fill(symbol); }
    else if (symbol != 'X' && symbol != 'O'){
        IllegalCharException ichar;
        ichar.set_illegal(symbol);
        throw ichar; }
    return symbol;
}

bool operator== (const Board& firstA, const Board& secondB){
    if(firstA.boardSize != secondB.boardSize) return false;
    for(int rows = 0; rows < (firstA.boardSize); rows++)
    	    for(int columns = 0; columns < (firstA.boardSize); columns++)
    	       if(firstA.gameBoard[rows][columns] != secondB.gameBoard[rows][columns]) return false;
    return true;
}

bool operator!= (const Board& firstA, const Board& secondB){ return !(firstA == secondB); } 
