#include "exceptions.hpp"

struct pairs{
    int first; //row
    int second; //column
};

class Board{
    
    private:
    char** gameBoard;
    int boardSize;
    
    public:
    Board();
    Board(Board&);
	Board(int); //c'tor
	~Board(); // de'tor
	int getSize();
    
    friend ostream& operator<<(ostream& os, Board& b); //input
    char* getRow(int); // will return a pointer to the beginning of the rows at array [x,0]
    char* getColumn(int); // will return a pointer to the beginning of the column [0,y]
    
    Board& operator= (Board&);
    char operator= (char);

    char& operator[] (const pairs);
    const char& operator[] (const pairs) const;
    
    void fill(char);
    void dealloc();
    char** alloc(int);
    
};

    inline ostream& operator<< (ostream& os, Board& b){
        
		for(int rows = 0; rows < b.boardSize; rows++){
			for(int columns = 0; columns < b.boardSize; columns++ ){
				os << b.gameBoard[rows][columns];
			}
			os << endl;
		}
        return os;
    }
    