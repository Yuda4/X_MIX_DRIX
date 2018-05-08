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
	int getSize();
    
    friend ostream& operator<<(ostream& os, const Board& b); //input
    place* getRow(int); // will return a pointer to the beginning of the rows at array [x,0]
    place* getColumn(int); // will return a pointer to the beginning of the column [0,y]
    
    Board& operator= (Board&);
    char operator= (char);
    friend bool operator== (const Board&, const Board&);
    friend bool operator!= (const Board&, const Board&);

    place& operator[] (const pairs);
    const char operator[] (const pairs) const;
    
    void fill(char);
    void alloc(int);
    
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
