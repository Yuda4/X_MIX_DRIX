#include "Champion.h"
const Coordinate Champion::play(const Board& board) { 
	if((counter*-1+1)%2==0){
		Coordinate c{board.size()+counter,x};
		if (board[c]=='.') return c;
		
	}else{
		Coordinate c{x,board.size()+counter};
		if (board[c]=='.'){
		x+=1;
		counter-=1;
		return c;	
		} 
	}
	return {0,0};  // did not find an empty square - play on the top-left
}