#include "Board.hpp"

Board :: Board (int size){
    this-> boardSize = size;
	gameBoard = alloc(boardSize);
	fill('.');
}

Board :: Board(Board& other){
    this-> boardSize = other.getSize();
	gameBoard = alloc(boardSize);
	 for(int rows = 0; rows < (this-> boardSize); rows++)
    	    for(int columns = 0; columns < (this-> boardSize); columns++)
    	       (this-> gameBoard[rows][columns]) = other.gameBoard[rows][columns];
}

Board :: ~Board(){
    dealloc();
}

int Board ::getSize() { return this-> boardSize; }

char** Board :: alloc(int size){
	char ** new_board = new char *[size];
	for(int i = 0; i < size; i++){
		new_board[i] = new char[size];
	}
	return new_board;
}

void Board :: dealloc(){
	for(int i = 0; i < (this-> boardSize); i++){
		delete [] gameBoard[i];
	}
	delete [] gameBoard;
}

void Board :: fill(char symbol){
        for(int rows = 0; rows < (this-> boardSize); rows++)
    	    for(int columns = 0; columns < (this-> boardSize); columns++)
    	       (this-> gameBoard[rows][columns]) = symbol;
}

char& Board :: operator[] (const pairs index){
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

const char& Board ::operator[] (const pairs index) const{
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
