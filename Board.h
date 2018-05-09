#ifndef _BOARD_H
#define _BOARD_H
#include "place.hpp"
#include <iostream>
using namespace std;
#endif

struct pairs{
    int first; //row
    int second; //column
};

class Board{
    public:
    place** gameBoard;
    int boardSize;
    Board();
    Board(Board&);
    Board(int); 
    ~Board();
    void alloc();
    void dlloc();
	
    friend ostream& operator<<(ostream& os, const Board& b); //input
    
    Board& operator= (Board&);
    char operator= (char);
    friend bool operator== (const Board&, const Board&);
    friend bool operator!= (const Board&, const Board&);

    place& operator[] (const pairs);
    
    void fill(char);
};

    inline ostream& operator<< (ostream& os, const Board& b){
		for(int rows = 0; rows < b.boardSize; rows++){
			for(int columns = 0; columns < b.boardSize; columns++ ){
				os << (b.gameBoard[rows][columns]).get_sign();
			}
			os << endl;
		}
        return os;
    }
