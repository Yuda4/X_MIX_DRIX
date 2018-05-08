#include "Board.h"

Board :: Board (int size){
    this-> boardSize = size;
	gameBoard = alloc(boardSize);
}

Board :: Board(Board& other){
    this-> boardSize = other.getSize();
	gameBoard = alloc(boardSize);
	 for(int rows = 0; rows < (this-> boardSize); rows++)
    	    for(int columns = 0; columns < (this-> boardSize); columns++)
    	       (this-> gameBoard[rows][columns]) = other.gameBoard[rows][columns];
}

Board :: ~Board(){
    for(int i = 0; i < (this-> boardSize); i++){
		delete [] gameBoard[i];
	}
	delete [] gameBoard;
}

int Board ::getSize() { return this-> boardSize; }

place** Board :: alloc(int size){
	place** new_board = new place*[size];
	for(int i = 0; i < size; i++){
		new_board[i] = new place[size];
	}
	return new_board;
}

void Board :: fill(char symbol){
        for(int rows = 0; rows < (this-> boardSize); rows++)
    	    for(int columns = 0; columns < (this-> boardSize); columns++)
    	       (this-> gameBoard[rows][columns]) = symbol;
}

place& Board :: operator[] (const pairs index){
    if(index.first >= getSize() || index.second >= getSize()){
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

const char Board ::operator[] (const pairs index) const{
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
    return gameBoard[index.first][index.second].get_sign();
}

Board& Board ::operator= (Board& other){
    this-> boardSize = other.getSize();
	gameBoard = alloc(boardSize);
	 for(int rows = 0; rows < (this-> boardSize); rows++)
    	    for(int columns = 0; columns < (this-> boardSize); columns++)
    	       (this-> gameBoard[rows][columns]) = other.gameBoard[rows][columns];
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
