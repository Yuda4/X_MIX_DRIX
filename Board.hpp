#include <iostream>
using namespace std;

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
	Board(int); //c'tor
	~Board(); // de'tor
	int getSize() { return this-> boardSize; }
    
    friend ostream& operator<<(ostream& os, Board& b); //input
    char* getRow(int x); // will return a pointer to the beginning of the rows at array [x,0]
    char* getColumn(int y); // will return a pointer to the beginning of the column [0,y]
    
    Board& operator= (Board&);
    Board& operator= (char);
    
    char& operator[] (const pairs index);
    const char& operator[] (const pairs index) const;
    
    void fill(char);
    void fill(char symbol, int row, int col);
    void dealloc();
    char** alloc(int size);
    
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
    
	/*Board :: Board(int size){  //c'tor
		this-> boardSize = size;
		gameBoard = (char**)malloc(size*size);
		fill('.');
	}*/
	
	char** Board :: alloc(int size){
    	this-> boardSize = size;
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
    
    Board :: Board (int size){
    	gameBoard = alloc(size);
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
	
	
