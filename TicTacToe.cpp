#include "TicTacToe.h"
#include "exceptions.hpp"

const Board& TicTacToe :: board()const{
    return _playGround;
}

Player& TicTacToe :: winner()const{
    return *this->_winnerPlayer;
}

bool TicTacToe :: game_over(const char sign) {
    if(check_row(sign) || check_colm(sign) || check_diagonal(sign)) return true;
    return false;
}

bool TicTacToe :: check_row(const char sign) {
    int appears = 0;
    for (int x=0; x<(this->_playGround.boardSize); ++x) {
		for (int y=0; y<(this->_playGround.boardSize); ++y) {
		    Coordinate c{x,y};
			if ((this->_playGround)[c]==sign) {
				appears++;
			}
		}
		if(appears == _playGround) return true;
		appears = 0;
	}
	return false;
}

bool TicTacToe :: check_colm(const char sign) {
    int appears = 0;
    for (int y=0; y<(this->_playGround.boardSize); ++y) {
		for (int x=0; x<(this->_playGround.boardSize); ++x) {
		    Coordinate c{x,y};
			if (_playGround[c]==sign) {
				appears++;
			}
		}
		if(appears == _playGround) return true;
		appears = 0;
	}
	return false;
}

bool TicTacToe :: check_diagonal(const char sign) {
    int appears = 0;
    //Check diagonal - left to right
    for (int x=0; x<(this->_playGround.boardSize); ++x) {
        Coordinate c{x,x};
			if (_playGround[c]==sign) {
				appears++;
			}
		if(appears == _playGround) return true;
		appears = 0;
	}
	//Check diagonal - right to left
    for (int x=(this->_playGround.boardSize)-1; x>=0; --x) {
        //Coordinate c{this->_playGround.boardSize-x-1,x};
        Coordinate c{x,x};
		if (_playGround[c]==sign) {
			appears++;
		}
	if(appears == _playGround) return true;
	appears = 0;
    }
	return false;
}

void TicTacToe :: play(Player& xPlayer, Player& oPlayer){
  
    this-> _playGround = '.';
    xPlayer.setChar('X');
    oPlayer.setChar('O');
    
    if(counter%2==0){
        try{
        counter++;
        
        if (_playGround[xPlayer.play(_playGround)] == '.'){
            _playGround[xPlayer.play(_playGround)] = 'X';
        }else throw IllegalCharException();
        if(counter >= _size){ 
            if (game_over('X')){
              (this->_winnerPlayer) = &xPlayer;
              return;  
            } 
            if (counter==_size*_size){
                (this->_winnerPlayer) = &oPlayer;
                return;
            }
        }
        }catch(const IllegalCoordinateException& ex){
            (this->_winnerPlayer) = &oPlayer;
            return;
        }catch(const IllegalCharException& ex){
            (this->_winnerPlayer) = &oPlayer;
            return;
        }catch(const string& ex){
            (this->_winnerPlayer) = &oPlayer;
            return;
        }
    }else{
        try{
        counter++;
        if (_playGround[xPlayer.play(_playGround)] == '.'){
            _playGround[xPlayer.play(_playGround)] = 'O';
        }else throw IllegalCharException();
        if(counter >= _size){ 
            if (game_over('O')){
                (this->_winnerPlayer) = &oPlayer;
                return;  
            } 
            if (counter==_size*_size){
                (this->_winnerPlayer) = &oPlayer;
                return;
            }
        }
        }catch(const IllegalCoordinateException& ex){
            (this->_winnerPlayer) = &xPlayer;
            return;
        }catch(const IllegalCharException& ex){
            (this->_winnerPlayer) = &xPlayer;
            return;
        }catch(const string& ex){
            (this->_winnerPlayer) = &xPlayer;
            return;
        }
    return;
    }
    
    
    
    
}



/*const Coordinate TicTacToe :: play(const Board& board) override;*/