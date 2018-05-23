#include "Champion.h"
const Coordinate Champion::play(const Board& board) {
	Coordinate c{board.size()-1,0};
	if(board[c]=='.') return c;
	else{
		Coordinate c{0,board.size()-1};
		if(board[c]=='.') return c;
		else{
			for(int x=1; x<board.size()-1; ++x){
				Coordinate c{board.size()-x-1,x};
				if(board[c]=='.') return c;
			}
		}
	}
	return {board.size()-1,board.size()-1};  // did not find an empty square - play on the top-left
}
