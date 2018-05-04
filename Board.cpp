#include <iostream>
using namespace std;
#include "Board.hpp"

Board :: Board (int size){
    this-> boardSize = size;
	gameBoard = alloc(boardSize);
	fill('.');
}

Board :: ~Board(){
    /*for(int rows = 0; rows < this-> boardSize; rows++){
	    for(int columns = 0; columns < this-> boardSize; columns++){
	        free(&gameBoard[rows][columns]);
	    }
	}
    delete [] gameBoard;*/
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
    for(int rows = 0; rows < (this-> boardSize); rows++){
	    for(int columns = 0; columns < (this-> boardSize); columns++){
	       (this-> gameBoard[rows][columns]) = symbol;
	    }
	}
}

void Board :: fill(char symbol, int row, int col){
    (this-> gameBoard[row][col]) = symbol;
}

char& Board :: operator[] (const pairs index){
    return gameBoard[index.first][index.second];
}

const char& Board ::operator[] (const pairs index) const{
    return gameBoard[index.first][index.second];
}

Board& Board ::operator= (Board& other){
    this-> boardSize = other.boardSize;
    this-> gameBoard [boardSize - 1][boardSize - 1] = { };
	 for(int rows = 0; rows < (this-> boardSize); rows++){
	    for(int columns = 0; columns < (this-> boardSize); columns++){
	        (this->gameBoard[rows][columns]) = other.gameBoard[rows][columns];
	    }
	}
    return *this;
}

Board& Board ::operator= (char symbol){
    if(symbol == '.'){
        fill('.');
    }
    
    return *this;
}

